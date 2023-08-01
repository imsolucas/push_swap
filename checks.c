/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:37:07 by djin              #+#    #+#             */
/*   Updated: 2023/08/01 13:49:51 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	error_exit(t_node *stack_a)
{
	clear_lst(stack_a, true);
	ft_printf("ERROR\n");
	exit(true);
}

long	ft_atol_checker(const char *str, t_node *stack_a)
{
	int	is_neg;
	int	results;

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
	if ((results * is_neg) > INT_MAX || (results * is_neg) < INT_MIN)
		error_exit(stack_a);
	return (results * is_neg);
}
