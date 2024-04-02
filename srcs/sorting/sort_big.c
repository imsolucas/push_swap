/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 06:55:33 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 16:19:30 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lets_sort_decending(t_stack *stack_a, t_stack *stack_b)
{
	int		*steps;
	t_size	*sort;
	int		index;
	int		i;
	t_node	*current_a;

	sort = &(t_size){0};
	sort->size = lst_count_num(stack_a);
	while (sort->size)
	{
		add_index_to_stack(stack_a);
		steps = malloc(sizeof(int) * (sort->size + 1));
		set_up_count_rotations(stack_a, stack_b);
		current_a = stack_a->head;
		i = 0;
		while (current_a)
		{
			steps[i++] = total_steps(current_a);
			current_a = current_a->next;
		}
		sorting(stack_a, stack_b, steps, sort);
		sort->size--;
		free(steps);
	}
	sort_decending(stack_b);
}

void	empty_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int	size_b;

	size_b = lst_count_num(stack_b);
	while (size_b--)
	{
		if (stack_b->head->num < stack_b->tail->num)
			rrb(stack_b, true);
		pa(stack_a, stack_b, true);
	}
}
