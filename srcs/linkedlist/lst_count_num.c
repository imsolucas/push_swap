/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_count_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:23:29 by djin              #+#    #+#             */
/*   Updated: 2024/02/14 16:27:26 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_count_num(t_node *stack)
{
	int		count;
	t_node	*tmp;

	count = 0;
	tmp = stack_go_back(stack, false);
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
