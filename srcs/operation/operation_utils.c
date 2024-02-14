/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:48:41 by djin              #+#    #+#             */
/*   Updated: 2024/02/14 15:42:01 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*tmp;
	t_node	*head;

	(*stack) = stack_go_back(*stack, false);
	if (*stack && (*stack)->next)
	{
		head = *stack;
		tmp = head->next;
		head->prev = tmp;
		head->next = tmp->next;
		tmp->prev = NULL;
		tmp->next = head;
		*stack = tmp;
	}
}

void	push(t_node **stack_from, t_node **stack_to)
{
	t_node	*tmp;

	if (*stack_from)
	{
		tmp = *stack_from;
		*stack_from = (*stack_from)->next;
		if (*stack_from)
			(*stack_from)->prev = NULL;
		tmp->next = *stack_to;
		if (*stack_to)
			(*stack_to)->prev = tmp;
		*stack_to = tmp;
	}
}

void	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		tmp2 = *stack;
		while (tmp2->next)
			tmp2 = tmp2->next;
		*stack = tmp->next;
		tmp->next = NULL;
		tmp2->next = tmp;
	}
}

void	reverse_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		tmp2 = *stack;
		while (tmp2->next->next)
			tmp2 = tmp2->next;
		*stack = tmp2->next;
		tmp2->next = NULL;
		(*stack)->next = tmp;
	}
}
