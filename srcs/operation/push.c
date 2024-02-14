/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:52:19 by djin              #+#    #+#             */
/*   Updated: 2024/02/14 15:43:37 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
}
