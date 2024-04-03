/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:20:39 by codespace         #+#    #+#             */
/*   Updated: 2024/04/03 14:30:20 by geibo            ###   ########.fr       */
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
	while (current_a)
	{
		if (current_a->index > size / 2)
			current_a->steps.rra += (size - current_a->index);
		else
			current_a->steps.ra += (current_a->index);
		current_a = current_a->next;
	}
}

void	max_steps_to_top_b(t_node *current_a, t_stack *stack_b)
{
	int		max_b;
	int		size_b;
	t_node	*current_b;

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

void	count_b_steps(t_node *current_a, t_stack *stack_b, t_node *current_b)
{
	int		size_b;

	size_b = lst_count_num(stack_b);
	if (current_b->next->index > (size_b / 2))
		current_a->steps.rrb += (size_b - current_b->next->index);
	else
		current_a->steps.rb += (current_b->next->index);
}
