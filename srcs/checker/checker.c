/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:16:13 by geibo             #+#    #+#             */
/*   Updated: 2024/04/05 10:00:27 by djin             ###   ########.fr       */
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

void	check_input(t_stack *stack_a, t_stack *stack_b)
{
	char	*input;

	input = get_next_line(0);
	while (input != NULL)
	{
		if (!is_valid(input))
			error_input("Error\n", input, stack_a);
		sort(stack_a, stack_b, input);
		free(input);
		input = get_next_line(0);
	}
	free(input);
	if (!is_not_sorted(stack_a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;

	stack_a = (t_stack){0};
	stack_b = (t_stack){0};
	i = 0;
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
			error_exit("Error\n");
		argv = ft_split(argv[1], ' ');
		i = -1;
	}
	if (argc > 1)
		add_stack(&stack_a, &i, argv, argc);
	check_input(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (argc == 2)
		free_argv(argv);
}
