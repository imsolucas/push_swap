/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:37:07 by djin              #+#    #+#             */
/*   Updated: 2024/02/24 20:36:21 by djin             ###   ########.fr       */
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

void	print_stack(t_stack *a, t_stack *b, t_node *tmp_a, t_node *tmp_b)
{
	if (a->head != NULL)
		tmp_a = a->head;
	if (b->head != NULL)
		tmp_b = b->head;
	ft_printf("stack_a: ");
	while (tmp_a != NULL)
	{
		ft_printf("%d ", tmp_a->num);
		if (tmp_a->next == NULL)
			break ;
		ft_printf("-> ");
		tmp_a = tmp_a->next;
	}
	ft_printf("\nstack_b: ");
	while (tmp_b != NULL)
	{
		ft_printf("%d ", tmp_b->num);
		if (tmp_b->next == NULL)
			break ;
		ft_printf("-> ");
		tmp_b = tmp_b->next;
	}
	ft_printf("\n");
}
	// tmp_a = a->head;
	// ft_printf("\nindex: ");
	// while (tmp_a)
	// {
	// 	ft_printf("%d, ", tmp_a->index);
	// 	if (tmp_a->next == NULL)
	// 		break ;
	// 	tmp_a = tmp_a->next;
	// }\
