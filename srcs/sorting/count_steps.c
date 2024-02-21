/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:20:39 by codespace         #+#    #+#             */
/*   Updated: 2024/02/21 10:21:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_steps_to_top_a(t_stack *stack_a)
{
	t_node	*current_a;
	int		size;
	int		size_b;

	size = lst_count_num(stack_a);
	current_a = stack_a->head;
	set_every_step_to_zero(stack_a);
	while (current_a)
	{
		if (current_a->index > size / 2)
			current_a->steps.rra += (size - current_a->index);
		else
			current_a->steps.ra += (current_a->index);
		current_a = current_a->next;
	}
}

void	count_steps_to_top_b(t_stack *stack_b, t_node *current_a)
{
	t_node	*current_b;
	int		max_b;
	int		size_b;

	size_b = lst_count_num(stack_b);
	current_b = stack_b->head;
	max_b = max_number(stack_b);
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

void	set_up_count_rotations(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;
	int		size;
	
	size = lst_count_num(stack_a);
	current = stack_a->head;
	set_every_step_to_zero(stack_a);
	count_steps_to_top_a(stack_a);
	steps_to_handle_min_max(stack_a, stack_b);
	// steps_to_handle_num_between(stack_a, stack_b);
	// set_rr_rrr(stack_a);
}

void	count_b_steps(t_node *current_a, t_stack *stack_b, t_node *current_b)
{
	int		size_b;

	size_b = lst_count_num(stack_b);
	if (current_b->index > size_b / 2)
		current_a->steps.rrb += (size_b - current_b->index);
	else
		current_a->steps.rb += (current_b->index);
}
