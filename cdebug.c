/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdebug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:12:34 by djin              #+#    #+#             */
/*   Updated: 2023/07/26 20:56:49 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack_a, t_node *stack_b)
{
	while (stack_a->content != 0 || stack_b->content != 0)
	{
		if (stack_a != NULL)
		{
			ft_printf("%d ", stack_a->content);
			stack_a = stack_a->next;
		}
		else if (stack_b != NULL)
		{
			ft_printf("%d ", stack_b->content);
			stack_b = stack_b->next;
		}
	}
	ft_printf("\n");
}
