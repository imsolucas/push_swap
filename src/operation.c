/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:56:10 by djin              #+#    #+#             */
/*   Updated: 2024/01/09 17:12:38 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_node **stack)
{
	t_node	*tmp;
	t_node	*head;

	(*stack) = stack_go_back(*stack, false);
	if (*stack && (*stack)->next)
	{
		head = *stack; // 1
		tmp = head->next; // 2
		head->prev = tmp; // 1->prev = 2
		head->next = tmp->next; // 1->next = 3
		tmp->prev = NULL; // 2->prev = NULL
		tmp->next = head; // 2->next = 1
		*stack = tmp; // *stack = 2
	}
}

void	push(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	*stack_a = stack_go_back(*stack_a, false);
	tmp = *stack_a;
	printf("%d\n", (*stack_a)->num);
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	if (*stack_b)
	{
		(*stack_b)->next = tmp;
		swap(stack_b);
	}
	(*stack_b) = tmp;
	(*stack_b)->next = tmp;
	(*stack_b) = (*stack_b)->next;
	*stack_b = stack_go_back(*stack_b, false);
	printf("%d\n", (*stack_b)->num);
}

void	rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		tmp2 = *stack;
		while (tmp->next)
			tmp = tmp->next;
		*stack = (*stack)->next;
		tmp->next = tmp2;
		tmp2->next = NULL;
	}
}

void	reverse_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*tmp2;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		while (tmp->next->next)
			tmp = tmp->next;
		tmp2 = tmp->next;
		tmp->next = NULL;
		tmp2->next = *stack;
		*stack = tmp2;
	}
}
