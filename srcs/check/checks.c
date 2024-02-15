/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:37:07 by djin              #+#    #+#             */
/*   Updated: 2024/02/14 20:53:23 by djin             ###   ########.fr       */
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

void	add_node(t_node **stack, int *i, char **argv)
{
	while (argv[++(*i)])
		*stack = add_stack(*stack, ft_atoi(argv[*i]));
	*stack = stack_go_back(*stack, false);
	(*stack)->head = *stack;
	(*stack)->tail = stack_go_back(*stack, true);
}

void	error(char	*str)
{
	ft_printf("ERROR: %s\n", str);
	exit(true);
}

void	print_stack(t_node *stack_a, t_node *stack_b)
{
	ft_printf("Stack A: ");
	while (stack_a)
	{
		ft_printf("%d ", stack_a->num);
		if (stack_a->next == NULL)
			break ;
		stack_a = stack_a->next;
	}
	ft_printf("\nStack B: ");
	while (stack_b)
	{
		ft_printf("%d ", stack_b->num);
		if (stack_b->next == NULL)
			break ;
		stack_b = stack_b->next;
	}
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
