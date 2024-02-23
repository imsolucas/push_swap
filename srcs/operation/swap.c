/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:31:45 by djin              #+#    #+#             */
/*   Updated: 2024/02/23 06:52:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	ft_printf("sa\n");
	swap(stack_a);
}

void	sb(t_stack *stack_b)
{
	ft_printf("sb\n");
	swap(stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("ss\n");
	swap(stack_a);
	swap(stack_b);
}
