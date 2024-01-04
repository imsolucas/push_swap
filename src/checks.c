/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:37:07 by djin              #+#    #+#             */
/*   Updated: 2024/01/04 21:34:58 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_space(char c)
{
	char	*str;

	str = "\t\n\r\f\v ";
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

void	error(char	*str)
{
	ft_printf("ERROR: %s\n", str);
	exit(true);
}

void	print_stack(t_node *stack_a)
{
	stack_a = stack_go_back(stack_a, false);
	while (stack_a)
	{
		if (stack_a != NULL)
		{
			ft_printf("stack_a: %d\n", stack_a->num);
			stack_a = stack_a->next;
		}
	}
}

long	ft_atol_checker(const char *str)
{
	int		is_neg;
	long	results;

	is_neg = 1;
	results = 0;
	if (check_space(*str))
		str++;
	if (*str == '-')
		is_neg = -1;
	if ((*str) == '-' || (*str) == '+')
		str++;
	while ((*str) >= '0' && (*str) <= '9')
	{
		results = (results * 10) + ((*str) - '0');
		str++;
	}
	results = results * is_neg;
	if (results > INT_MAX || results < INT_MAX)
		error("Too Much Number Master");
	return (results);
}
