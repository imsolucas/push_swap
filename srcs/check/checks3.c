/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geibo <geibo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:48:36 by djin              #+#    #+#             */
/*   Updated: 2024/04/03 23:27:36 by geibo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current->next)
	{
		if (current->num > current->next->num)
			return (false);
		current = current->next;
	}
	return (true);
}

void	check_errors(t_stack *stack_a, int argc, char **argv)
{
	if (is_sorted(stack_a))
		error_free_exit(NULL, stack_a, argc, argv);
}

int	ft_atol(char *str, t_stack *stack_a, int argc, char **argv)
{
	int				i;
	long long int	num;
	int				sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error_free_exit("Error\n", stack_a, argc, argv);
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	if ((num * sign) > 2147483647 || (num * sign) < -2147483648)
		error_free_exit("Error\n", stack_a, argc, argv);
	num *= sign;
	return ((int)num);
}
