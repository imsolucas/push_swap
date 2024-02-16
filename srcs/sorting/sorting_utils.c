/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:59:10 by djin              #+#    #+#             */
/*   Updated: 2024/02/16 08:55:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank(t_stack *stacks)
{
	t_node	*tmp;
	int		rank;
	int		i;

	tmp = stacks->head;
	while (tmp)
	{
		rank = 1;
		i = 0;
		while (stacks->head)
		{
			if (tmp->num > stacks->head->num)
				rank++;
			stacks->head = stacks->head->next;
			i++;
		}
		tmp->rank = rank;
		stacks->head = tmp;
		tmp = tmp->next;
	}
}
