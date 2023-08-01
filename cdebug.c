/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cdebug.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:12:34 by djin              #+#    #+#             */
/*   Updated: 2023/08/01 13:48:38 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *stack_a, t_node *stack_b)
{
	stack_a = lst_first_last(stack_a, false);
	stack_b = lst_first_last(stack_b, false);
	while (stack_a || stack_b)
	{
		if (stack_a != NULL)
		{
			ft_printf("stack_a: %d\n", stack_a->content);
			stack_a = stack_a->next;
		}
		else if (stack_b != NULL)
		{
			ft_printf("stack_b: %d\n", stack_b->content);
			stack_b = stack_b->next;
		}
	}
	// ft_printf("\n");
}
