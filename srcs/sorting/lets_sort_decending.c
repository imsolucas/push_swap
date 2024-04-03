/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_sort_decending.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:51:15 by geibo             #+#    #+#             */
/*   Updated: 2024/04/03 14:11:01 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_steps_to_top_b(t_stack *stack_b, t_node *current_a)
{
	t_node	*current_b;
	int		max_b;
	int		size_b;

	max_b = max_number(stack_b);
	size_b = lst_count_num(stack_b);
	current_b = stack_b->head;
	while (current_b)
	{
		if (current_b->num == max_b)
		{
			if (current_b->index > (size_b / 2))
				current_a->steps.rrb += (size_b - current_b->index);
			else
				current_a->steps.rb += (current_b->index);
		}
		current_b = current_b->next;
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

void	handle_num_between_decending(t_stack *stack_a, t_stack *stack_b)
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

void	set_up_count_rotations(t_stack *stack_a, t_stack *stack_b)
{
	set_every_step_to_zero(stack_a);
	count_steps_to_top_a(stack_a);
	steps_to_handle_min_max(stack_a, stack_b);
	handle_num_between_decending(stack_a, stack_b);
	set_rr_rrr(stack_a);
}
