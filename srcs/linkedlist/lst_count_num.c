/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_count_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:23:29 by djin              #+#    #+#             */
/*   Updated: 2024/02/19 08:27:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_count_num(t_stack *stacks)
{
	int		count;
	t_node	*current;

	current = stacks->head;
	count = 0;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}
