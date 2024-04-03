/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:55:18 by geibo             #+#    #+#             */
/*   Updated: 2024/04/03 15:21:44 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_space(char c)
{
	char	*str;

	str = "\t\n\r\f\v ";
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

void	error_free_exit(char *str, t_stack *stack_a)
{
	ft_printf("%s", str);
	free_stack(stack_a);
	exit(1);
}

void	is_num_dup(t_stack *stack_a)
{
	t_node	*current_a;
	t_node	*tmp_a;

	current_a = stack_a->head;
	while (current_a)
	{
		tmp_a = current_a->next;
		while (tmp_a)
		{
			if (current_a->num == tmp_a->num)
				error_free_exit("Error\n", stack_a);
			tmp_a = tmp_a->next;
		}
		current_a = current_a->next;
	}
}

bool	only_one_num(t_stack *stack_a)
{
	t_node	*current_a;

	current_a = stack_a->head;
	if (current_a->next == NULL)
		return (true);
	return (false);
}
