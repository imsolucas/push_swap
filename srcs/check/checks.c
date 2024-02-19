/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:37:07 by djin              #+#    #+#             */
/*   Updated: 2024/02/19 17:05:52 by djin             ###   ########.fr       */
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

// void	add_node(t_node **stack, int *i, char **argv)
// {
// 	while (argv[++(*i)])
// 		*stack = add_stack(*stack, ft_atoi(argv[*i]));
// 	*stack = stack_go_back(*stack, false);
// 	(*stack)->head = *stack;
// 	(*stack)->tail = stack_go_back(*stack, true);
// 	// ft_printf("stack->tail->num: %d\n", (*stack)->tail->num);
// }

void	add_stack(t_stack *stack, int *i, char **argv)
{
	while (argv[++(*i)])
		link_node(stack, create_stack(ft_atoi(argv[*i])));
}

void	error(char	*str)
{
	ft_printf("ERROR: %s\n", str);
	exit(true);
}

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = NULL;
	tmp_b = NULL;
	if (stack_a->head != NULL)
		tmp_a = stack_a->head;
	if (stack_b->head != NULL)
		tmp_b = stack_b->head;
	ft_printf("stack_a: ");
	while (tmp_a != NULL)
	{
		ft_printf("%d ", tmp_a->num);
		if (tmp_a->next == NULL)
			break ;
		tmp_a = tmp_a->next;
	}
	ft_printf("\nstack_b: ");
	while (tmp_b != NULL)
	{
		ft_printf("%d ", tmp_b->num);
		tmp_b = tmp_b->next;
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
