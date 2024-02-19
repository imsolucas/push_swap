/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:38:07 by djin              #+#    #+#             */
/*   Updated: 2024/02/19 17:07:55 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	if (stack->head->num > stack->head->next->num)
		sa(stack);
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
		sa(stack);
		ra(stack);
	}
	else if (first_rank == 2 && last_rank == 3)
		sa(stack);
	else if (first_rank == 2 && last_rank == 1)
		rra(stack);
	else if (first_rank == 3 && last_rank == 1)
	{
		sa(stack);
		rra(stack);
	}
	else if (first_rank == 3 && last_rank == 2)
		ra(stack);
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	rank(stack_a);
	while (stack_a->head->rank != 1)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	rank(stack_a);
	while (stack_a->head->rank != 1)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_big(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
}
