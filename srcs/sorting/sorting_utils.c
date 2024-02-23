/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:59:10 by djin              #+#    #+#             */
/*   Updated: 2024/02/23 06:16:19 by codespace        ###   ########.fr       */
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

void	steps_to_handle_min_max(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	int		min_b;
	int		max_b;

	add_index_to_stack(stack_b);
	min_b = min_number(stack_b);
	max_b = max_number(stack_b);
	current_a = stack_a->head;
	while (current_a)
	{
		if (current_a->num < min_b || current_a->num > max_b)
			count_steps_to_top_b(stack_b, current_a);
		current_a = current_a->next;
	}
}

void	steps_to_handle_num_between(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;

	add_index_to_stack(stack_b);
	current_a = stack_a->head;
	while (current_a)
	{
		sort_in_between(current_a, stack_b);
		current_a = current_a->next;
	}
}
