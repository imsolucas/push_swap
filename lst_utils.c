/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:47:36 by djin              #+#    #+#             */
/*   Updated: 2023/07/24 20:00:17 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//go to the last node;
t_node	*lst_first_last(t_node *node, bool is_last)
{
	if (!is_last)
	{
		while (node != NULL && node -> prev != NULL)
			node = node -> prev;
		return (node);
	}
	else
	{
		while (node != NULL && node -> next != NULL)
			node = node -> next;
		return (node);
	}
}

//removes all the lst
void	clear_lst(t_node *node)
{
	t_node	*tmp;

	if (!node)
		return ;
	node = lst_last(node);
	while (node)
	{
		tmp = node -> next;
		free(node);
		node = tmp;
	}
}

//create a new node
t_node	*new_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	node -> prev = NULL;
	return (node);
}

//joins the node together
//address of new will point to the prev node address
//address of node will point to new
t_node	*node_join(t_node *node, int content)
{
	t_node	*new;

	new = new_node(content);
	if (!new)
		return (NULL);
	if (!node)
		return (new);
	node -> next = new;
	new -> prev = node;
	return (new);
}
