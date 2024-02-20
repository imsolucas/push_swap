/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:59:10 by djin              #+#    #+#             */
/*   Updated: 2024/02/20 13:45:00 by codespace        ###   ########.fr       */
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

void	count_steps_to_top(t_stack *stack, bool is_a)
{
	t_node	*current;
	int		size;

	size = lst_count_num(stack);
	current = stack->head;
	set_every_step_to_zero(stack);
	while (current)
	{
		if (is_a)
		{
			if (current->index > size / 2)
				current->steps.rra += (size - current->index);
			else
				current->steps.ra += (current->index);
		}
		else
		{
			if (current->index > size / 2)
				current->steps.rrb += (size - current->index);
			else
				current->steps.rb += (current->index);
		}
	}
}
