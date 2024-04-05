/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:04:33 by geibo             #+#    #+#             */
/*   Updated: 2024/04/05 08:52:55 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_input(char *str, char *input, t_stack *stack_a)
{
	ft_putstr_fd(str, 2);
	free_stack(stack_a);
	if (input != NULL)
		free(input);
	exit(1);
}

bool	is_valid(char *str)
{
	if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "sb\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "ss\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "pa\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "pb\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "ra\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rb\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rr\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rra\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0
		|| ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
		return (true);
	return (false);
}

bool	not_empty(t_stack *stack_b)
{
	t_node	*current_b;

	current_b = stack_b->head;
	if (current_b)
		return (true);
	return (false);
}

bool	is_not_sorted(t_stack *stack_a)
{
	t_node	*current_a;

	current_a = stack_a->head;
	while (current_a->next)
	{
		if (current_a->num > current_a->next->num)
			return (true);
		current_a = current_a->next;
	}
	return (false);
}

void	sort(t_stack *stack_a, t_stack *stack_b, char *str)
{
	if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
		sa(stack_a, false);
	else if (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
		sb(stack_b, false);
	else if (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0)
		ss(stack_a, stack_b, false);
	else if (ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
		pa(stack_a, stack_b, false);
	else if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0)
		pb(stack_a, stack_b, false);
	else if (ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
		ra(stack_a, false);
	else if (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
		rb(stack_b, false);
	else if (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0)
		rr(stack_a, stack_b, false);
	else if (ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
		rra(stack_a, false);
	else if (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
		rrb(stack_b, false);
	else if (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
		rrr(stack_a, stack_b, false);
}
