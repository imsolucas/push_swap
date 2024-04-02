/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:31:16 by djin              #+#    #+#             */
/*   Updated: 2024/04/01 16:21:04 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a, bool print)
{
	if (print)
		ft_printf("rra\n");
	reverse_rotate(stack_a);
}

void	rrb(t_stack *stack_b, bool print)
{
	if (print)
		ft_printf("rrb\n");
	reverse_rotate(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, bool print)
{
	if (print)
		ft_printf("rrr\n");
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
