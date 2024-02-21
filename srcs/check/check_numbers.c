/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:34:10 by codespace         #+#    #+#             */
/*   Updated: 2024/02/21 10:34:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_number(t_stack *stack)
{
	int		min_num;
	t_node	*current;

	min_num = stack->head->num;
	current = stack->head;
	while (current)
	{
		if (min_num > current->num)
			min_num = current->num;
		current = current->next;
	}
	return (min_num);
}

int	max_number(t_stack *stack)
{
	int		max_num;
	t_node	*current;

	max_num = stack->head->num;
	current = stack->head;
	while (current)
	{
		if (max_num < current->num)
			max_num = current->num;
		current = current->next;
	}
	return (max_num);
}

int	min_steps(int *steps)
{
	int	min;
	int	i;

	i = 0;
	min = steps[i];
	while (steps[i])
	{
		if (min > steps[i])
			min = steps[i];
		i++;
	}
	i = 0;
	while (steps[i])
	{
		if (min == steps[i])
			break ;
		i++;
	}
	return (i);
}

int	total_steps(t_node *current_a)
{
	int		total;

	total = 0;
	total += current_a->steps.ra;
	total += current_a->steps.rb;
	total += current_a->steps.rr;
	total += current_a->steps.rra;
	total += current_a->steps.rrb;
	total += current_a->steps.rrr;
	return (total);
}
