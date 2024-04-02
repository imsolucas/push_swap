/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_decending.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 06:41:43 by codespace         #+#    #+#             */
/*   Updated: 2024/04/01 16:19:03 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_decending(t_stack *stack_b)
{
	int		size_b;
	int		max_b;
	int		max_index;
	t_node	*current_b;

	size_b = lst_count_num(stack_b);
	max_b = max_number(stack_b);
	max_index = max_number_index(stack_b);
	current_b = stack_b->head;
	while (current_b->num != max_b)
	{
		if (max_b > (size_b / 2))
			rrb(stack_b, true);
		else
			rb(stack_b, true);
		current_b = stack_b->head;
	}
}
