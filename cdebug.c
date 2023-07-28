/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdebug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:12:34 by djin              #+#    #+#             */
/*   Updated: 2023/07/28 11:52:40 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack_a, t_node *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a != NULL)
		{
			ft_printf("stack_a: %d ", stack_a->content);
			stack_a = stack_a->next;
		}
		else if (stack_b != NULL)
		{
			ft_printf("stack_b: %d ", stack_b->content);
			stack_b = stack_b->next;
		}
	}
	ft_printf("\n");
}
