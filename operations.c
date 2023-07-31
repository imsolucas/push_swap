/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:46:17 by djin              #+#    #+#             */
/*   Updated: 2023/07/31 14:00:46 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push(t_node **from, t_node **to)
{
	t_node	*tmp;
	t_node	*del_pnode;

	if (from == NULL || *from == NULL)
		return (true);
	*from = lst_first_last(*from, false);
	*to = lst_first_last(*to, false);
	tmp = (*from);
	tmp->next = NULL;
	(*to) = tmp;
	del_pnode = (*from)->next;
	del_pnode->prev = NULL;
	(*from) = del_pnode;
	return (true);
}

bool	rotate(t_node **stack, bool reverse)
{
	t_node	*tmp;

	*stack = lst_first_last(*stack, false);
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (true);
	if (!reverse)
	{
		tmp = (*stack);
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		tmp->next = NULL;
		lst_first_last(*stack, true)->next = tmp;
		tmp->prev = lst_first_last(*stack, true);
	}
	else
	{
		tmp = lst_first_last(*stack, true);
		lst_first_last(*stack, true)->prev->next = NULL;
		tmp->prev = NULL;
		tmp->next = (*stack);
	}
	return (true);
}
