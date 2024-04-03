/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:38:07 by djin              #+#    #+#             */
/*   Updated: 2024/04/03 17:29:54 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->head->num > stack->head->next->num)
		sa(stack, true);
}

void	sort_three(t_stack *stack)
{
	int	first_rank;
	int	last_rank;

	rank(stack);
	first_rank = stack->head->rank;
	last_rank = stack->tail->rank;
	if (first_rank == 1 && last_rank == 2)
	{
		sa(stack, true);
		ra(stack, true);
	}
	else if (first_rank == 2 && last_rank == 3)
		sa(stack, true);
	else if (first_rank == 2 && last_rank == 1)
		rra(stack, true);
	else if (first_rank == 3 && last_rank == 1)
	{
		sa(stack, true);
		rra(stack, true);
	}
	else if (first_rank == 3 && last_rank == 2)
		ra(stack, true);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	rank(stack_a);
	while (stack_a->head->rank != 1)
		ra(stack_a, true);
	pb(stack_a, stack_b, true);
	sort_three(stack_a);
	pa(stack_a, stack_b, true);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	rank(stack_a);
	while (stack_a->head->rank != 1)
	{
		if (stack_a->tail->rank == 1)
			rra(stack_a, true);
		else
			ra(stack_a, true);
	}
	pb(stack_a, stack_b, true);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b, true);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b, true);
	pb(stack_a, stack_b, true);
	lets_sort_decending(stack_a, stack_b);
	lets_sort_acending(stack_a, stack_b);
	empty_stack_b(stack_a, stack_b);
}
