/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 06:16:49 by codespace         #+#    #+#             */
/*   Updated: 2024/02/21 08:39:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_in_between(t_node *current_a, t_stack *stack_b)
{
	int		num_a;
	int		num_b;
	int		size_b;
	int		next_num_b;
	t_node	*current_b;

	size_b = lst_count_num(stack_b);
	num_a = current_a->num;
	num_b = current_b->num;
	current_b = stack_b->head;
	if (num_a > num_b && num_a < stack_b->tail->num)
		return;
	while (current_b)
	{
		next_num_b = current_b->next->num;
		if (num_a > next_num_b && num_a < num_b)
			count_b_steps(current_a, current_b, stack_b);
		current_b = current_b->next;
	}
}

 
