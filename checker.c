/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:21:43 by djin              #+#    #+#             */
/*   Updated: 2023/07/25 09:47:38 by djin             ###   ########.fr       */
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
	exit(1);
}

long	ft_atol_checker(const char *str, t_node *stack_a)
{
	long	num;
	int		result;

	num = 1;
	result = 0;
	while (check_space(*str))
		str++;
	if (*str == '-')
		num = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		error_exit(stack_a);
	while (*str >= '0' && *str <= '9')
	{
		if (!ft_isdigit(*str))
			error_exit(stack_a);
		result = (result * 10) + (*str - '0');
		str++;
	}
	if ((result * num) > 2147483647 || (result * num < -2147483648))
		error_exit(stack_a);
	return (num * result);
}

int	checks(t_node *stack_a, char *str)
{
	if (ft_atol_checker(str, stack_a))
		return (1);
	return (0);
}
