/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:29:26 by djin              #+#    #+#             */
/*   Updated: 2024/04/01 16:16:02 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, bool print)
{
	if (print)
		ft_printf("ra\n");
	rotate(stack_a);
}

void	rb(t_stack *stack_b, bool print)
{
	if (print)
		ft_printf("rb\n");
	rotate(stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b, bool print)
{
	if (print)
		ft_printf("rr\n");
	rotate(stack_a);
	rotate(stack_b);
}
