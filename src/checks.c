/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:37:07 by djin              #+#    #+#             */
/*   Updated: 2024/01/09 17:07:03 by djin             ###   ########.fr       */
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

void	print_stack(t_node *stack_a, t_node *stack_b)
{
	// stack_a = stack_go_back(stack_a, false);
	(void)stack_a;
	(void)stack_b;
	// stack_b = stack_go_back(stack_b, false);
	// while (true)
	// {
	// 	if (stack_a != NULL)
	// 	{
	// 		ft_printf("%d ", stack_a->num);
	// 		stack_a = stack_a->next;
	// 	}
	// 	else if (stack_b != NULL)
	// 	{
	// 		ft_printf("%d ", stack_b->num);
	// 		stack_b = stack_b->next;
	// 	}
	// 	else
	// 		break ;
	// }
	// printf("%d", (int)stack_b);
	// printf("%d", stack_a->num);
	ft_printf("\n");
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
