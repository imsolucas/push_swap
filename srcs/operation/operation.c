/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:35:21 by djin              #+#    #+#             */
/*   Updated: 2024/02/16 07:06:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_node **stack_a, t_node **stack_b)
{
	int	stack_len;

	stack_len = lst_count_num(*stack_a);
	if (stack_len == 2)
	{
		if ((*stack_a)->num > (*stack_a)->next->num)
			sa(stack_a);
	}
	// else if (stack_len == 3)
	// 	sort_three(stack_a);
	// else if (stack_len == 4)
	// 	sort_four(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
}
