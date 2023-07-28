/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:46:17 by djin              #+#    #+#             */
/*   Updated: 2023/07/28 17:36:30 by djin             ###   ########.fr       */
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
	tmp = (*stack);
	if (!reverse)
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
		tmp->next = NULL;
		tmp->prev = lst_first_last(*stack, true);
	}
}
