/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:59:10 by djin              #+#    #+#             */
/*   Updated: 2024/02/14 20:57:15 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rank(t_node *stack_a)
{
	t_node	*current;
	t_node	*compare;
	int		rank;

	current = stack_go_back(stack_a, false);
	while (current)
	{
		rank = 1;
		compare = stack_a->head;
		while (compare)
		{
			if (current->num > compare->num)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
		current = current->next;
	}
}
