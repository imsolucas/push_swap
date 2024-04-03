/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:44:51 by djin              #+#    #+#             */
/*   Updated: 2024/04/03 19:17:26 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	stack_a;
	t_stack	stack_b;

	i = 0;
	stack_a = (t_stack){0};
	stack_b = (t_stack){0};
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			return (0);
		argv = ft_split(argv[1], ' ');
		i = -1;
	}
	if (argc > 1)
		add_stack(&stack_a, &i, argv, argc);
	check_errors(&stack_a, argc, argv);
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (argc == 2)
		free_argv(argv);
}
// print_stack(&stack_a, &stack_b, NULL, NULL);
