/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:59:10 by djin              #+#    #+#             */
/*   Updated: 2024/04/02 21:53:47 by geibo            ###   ########.fr       */
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

void	add_index_to_stack(t_stack *stack)
{
	t_node	*current;
	int		index;

	current = stack->head;
	index = 0;
	while (current)
	{
		current->index = index++;
		current = current->next;
	}
}

void	set_every_step_to_zero(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		current->steps = (t_steps){0};
		current = current->next;
	}
}
