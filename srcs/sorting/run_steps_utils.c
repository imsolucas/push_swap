/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_steps_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 02:19:17 by codespace         #+#    #+#             */
/*   Updated: 2024/02/21 09:07:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rr_rrr(t_stack *stack_a)
{
	t_node	*current;

	current = stack_a->head;
	while (current)
	{
		if (current->steps.ra && current->steps.rb)
		{
			current->steps.ra--;
			current->steps.rb--;
			current->steps.rr++;
		}
		else if (current->steps.rra && current->steps.rrb)
		{
			current->steps.rra--;
			current->steps.rrb--;
			current->steps.rrr++;
		}
	}
}

void	run_steps(t_node *current, t_stack *stack_a, t_stack *stack_b)
{
	while (current->steps.ra--)
		ra(stack_a);
	while (current->steps.rb--)
		rb(stack_b);
	while (current->steps.rra--)
		rra(stack_a);
	while (current->steps.rrb--)
		rrb(stack_b);
	while (current->steps.rr--)
		rr(stack_a, stack_b);
	while (current->steps.rrr--)
		rrr(stack_a, stack_b);
}
