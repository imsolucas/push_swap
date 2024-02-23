/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:31:16 by djin              #+#    #+#             */
/*   Updated: 2024/02/23 06:52:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	ft_printf("rra\n");
	reverse_rotate(stack_a);
}

void	rrb(t_stack *stack_b)
{
	ft_printf("rrb\n");
	reverse_rotate(stack_b);
}

void	rrr(t_node *stack_a, t_node *stack_b)
{
	ft_printf("rrr\n");
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
