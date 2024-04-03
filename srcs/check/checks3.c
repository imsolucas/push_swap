/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:48:36 by djin              #+#    #+#             */
/*   Updated: 2024/04/03 19:23:48 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current->next)
	{
		if (current->num > current->next->num)
			return (false);
		current = current->next;
	}
	return (true);
}

void	check_errors(t_stack *stack_a, int argc, char **argv)
{
	// if (only_one_num(stack_a))
	// 	error_free_exit("NULL", stack_a, argc, argv);
	if (is_sorted(stack_a))
		error_free_exit(NULL, stack_a, argc, argv);
}
