/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:37:07 by djin              #+#    #+#             */
/*   Updated: 2024/04/05 09:54:21 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

bool	num_checks(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void	add_stack(t_stack *stack, int *i, char **argv, int argc)
{
	while (argv[++(*i)])
	{
		if (!num_checks(argv[*i]))
			error_free_exit("Error\n", stack, argc, argv);
		link_node(stack, create_stack(ft_atol(argv[*i], stack, argc, argv)));
	}
	is_num_dup(stack, argc, argv);
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
// }
