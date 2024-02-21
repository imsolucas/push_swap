/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 06:55:33 by codespace         #+#    #+#             */
/*   Updated: 2024/02/21 10:57:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lets_sort_decending(t_stack *stack_a, t_stack *stack_b)
{
	int		*steps;
	t_size	*sort;
	int		i;
	t_node	*current_a;

	sort = &(t_size){0};
	sort->size = lst_count_num(stack_a);
	sort->half_of_size = sort->size / 2;
	i = 0;
	add_index_to_stack(stack_a);
	steps = (int *)malloc(sizeof(int) * (sort->size));
	current_a = stack_a->head;
	while (sort->size--)
	{
		set_up_count_rotations(stack_a, stack_b);
		while (current_a)
		{
			steps[i] = total_steps(current_a);
			printf("%d ", steps[i++]);
			current_a = current_a->next;
		}
		printf("\n");
		current_a = stack_a->head;
		sort->index = min_steps(steps);
			printf("sort: %d\n", sort->index);
			printf("current: %d\n", current_a->index);
		while (current_a)
		{
			if (sort->index == current_a->index)
			{
				run_steps(current_a, stack_a, stack_b);
				pb(stack_a, stack_b);
				break;
			}

			current_a = current_a->next;
		}
		// free(steps);
	}
}

void	empty_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int	size_b;

	size_b = lst_count_num(stack_b);
	while (size_b--)
	{
		if (stack_b->head->num < stack_b->tail->num)
			rrb(stack_b);
		pa(stack_a, stack_b);
	}
}
