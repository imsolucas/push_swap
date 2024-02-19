/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:59:10 by djin              #+#    #+#             */
/*   Updated: 2024/02/19 07:23:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank(t_stack *stacks)
{
	t_node	*current;
	t_node	*compare;
	int		rank;

	current = stacks->head;
	while (current)
	{
		rank = 1;
		compare = stacks->head;
		while (compare)
		{
			if (current->num > compare->num)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
		current = current->next;
	}
}
