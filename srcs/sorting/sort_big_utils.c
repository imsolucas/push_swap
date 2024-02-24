/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:18:08 by codespace         #+#    #+#             */
/*   Updated: 2024/02/24 12:24:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack *stack_a, t_stack *stack_b, int *steps, t_size *sort)
{
	t_node	*current_a;

	current_a = stack_a->head;
	while (current_a)
	{
		if (current_a->index == min_steps_index(steps, sort))
		{
			run_steps(current_a, stack_a, stack_b);
			pb(stack_a, stack_b);
			current_a = stack_a->head;
			break;
		}
		current_a = current_a->next;
	}
}
