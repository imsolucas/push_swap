/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:24:12 by djin              #+#    #+#             */
/*   Updated: 2023/07/31 14:24:58 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;

	i = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		ft_split(argv[1], ' ');
	if (argc == 2)
		i = -1;
	if (argc > 1)
	{
		while (argv[++i])
		{
			if (checks(stack_a, argv[i]) == false)
			{
				error_exit(stack_a);
			}
			stack_a = node_join(stack_a, ft_atoi(argv[i]));
			stack_a = lst_first_last(stack_a, false);
			rotate(&stack_a, false);
			print_stack(stack_a, stack_b);
		}
	}
	// ft_printf ("\n");
}
