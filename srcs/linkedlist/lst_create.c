/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:17:21 by djin              #+#    #+#             */
/*   Updated: 2024/02/14 16:17:23 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*add_stack(t_node *stack, long num)
{
	t_node	*new_stack;

	new_stack = create_stack(num);
	if (!new_stack)
		return (NULL);
	if (!stack)
		return (new_stack);
	stack->next = new_stack;
	new_stack->prev = stack;
	return (new_stack);
}

t_node	*create_stack(int num)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->num = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*stack_go_back(t_node *stack, bool is_last)
{
	if (is_last == true)
	{
		while (stack->next != NULL && stack != NULL)
			stack = stack->next;
		return (stack);
	}
	else
	{
		while (stack->prev != NULL && stack != NULL)
			stack = stack->prev;
	}
	return (stack);
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	if (!(stack))
		return ;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		(stack) = tmp;
	}
}
