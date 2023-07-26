/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:46:17 by djin              #+#    #+#             */
/*   Updated: 2023/07/26 20:11:45 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



bool	push(t_node **from, t_node **to)
{
	t_node	*tmp;

	*from = lst_first_last(*from, false);
	*to = lst_first_last(*to, false);
	tmp = (*from);
	(*to) = (*from);
	(*from) = tmp -> next;
	clear_lst((*from)->prev, false);
	(*from)->prev = NULL;
	return (true);
}
