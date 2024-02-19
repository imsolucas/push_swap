/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:35:21 by djin              #+#    #+#             */
/*   Updated: 2024/02/19 08:33:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_len;

	stack_len = lst_count_num(stack_a);
	if (stack_len == 2)
		sort_two(stack_a);
	else if (stack_len == 3)
		sort_three(stack_a);
	else if (stack_len == 4)
		sort_four(stack_a, stack_b);
	else if (stack_len == 5)
		sort_five(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}
