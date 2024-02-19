/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:48:41 by djin              #+#    #+#             */
/*   Updated: 2024/02/19 17:07:17 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*current;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	current = stack->head;
	stack->head = current->next;
	current->next = stack->head->next;
	stack->head->next = current;
	stack->head->next->prev = stack->head;
	stack->head->prev = NULL;
	if (current->next != NULL)
		stack->head->next->next->prev = current;
}

void	push(t_stack *stack_from, t_stack *stack_to)
{
	t_node	*current;

	if (stack_from->head == NULL)
		return ;
	current = stack_from->head;
	stack_from->head = stack_from->head->next;
	if (stack_from->head != NULL)
		stack_from->head->prev = NULL;
	current->prev = NULL;
	current->next = NULL;
	if (stack_to->head == NULL)
	{
		stack_to->head = current;
		stack_to->tail = current;
	}
	else
	{
		current->next = stack_to->head;
		stack_to->head->prev = current;
		stack_to->head = current;
	}
}

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	first = stack->head;
	last = stack->tail;
	if (first == NULL || first->next == NULL)
		return ;
	stack->head = first->next;
	first->next = NULL;
	stack->head->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->tail = first;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	first = stack->head;
	last = stack->tail;
	if (first == NULL || first->next == NULL)
		return ;
	stack->tail = last->prev;
	stack->tail->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->head = last;
}
