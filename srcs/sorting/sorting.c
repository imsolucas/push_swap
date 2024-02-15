/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:38:07 by djin              #+#    #+#             */
/*   Updated: 2024/02/15 14:10:52 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a);
}

void	sort_three(t_node **stack_a)
{
	int	first_rank;
	int	last_rank;

	rank(*stack_a);
	first_rank = (*stack_a)->head->rank;
	last_rank = (*stack_a)->tail->rank;
	if (first_rank == 1 && last_rank == 2)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first_rank == 2 && last_rank == 1)
		rra(stack_a);
	else if (first_rank == 3 && last_rank == 2)
		ra(stack_a);
	else if (first_rank == 2 && last_rank == 3)
		sa(stack_a);
	else if (first_rank == 3 && last_rank == 1)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	{
		rank(*stack_a);
		tmp = (*stack_a)->head;
		while (tmp->rank != 4)
		{
			rra(stack_a);
			tmp = tmp->next;
		}
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
}
