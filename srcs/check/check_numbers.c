/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 03:34:10 by codespace         #+#    #+#             */
/*   Updated: 2024/02/23 06:44:18 by codespace        ###   ########.fr       */
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

int	min_steps_index(int *steps, t_size *sort)
{
	int		min;
	int		index;
	int		i;

	// printf("steps[1]: %d\n", steps[1]);
	min = steps[0];
	index = 0;
	i = 0;
	while (i < sort->size)
	{
		if (min > steps[i])
		{
			min = steps[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	max_number_index(t_stack *stack)
{
	int		max_num;
	int		index;
	t_node	*current;

	max_num = stack->head->num;
	index = 0;
	current = stack->head;
	while (current)
	{
		if (max_num < current->num)
		{
			max_num = current->num;
			index = current->index;
		}
		current = current->next;
	}
	return (index);
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
