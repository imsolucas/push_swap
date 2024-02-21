/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:37:59 by djin              #+#    #+#             */
/*   Updated: 2024/02/21 10:35:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_steps
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	pa;
	int	pb;
	int	sa;
	int	sb;
}	t_steps;

typedef struct s_size
{
	int size;
	int half_of_size;
	int index;
}	t_size;

typedef struct s_node
{
	int				num;
	int				rank;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
	t_steps			steps;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
}	t_stack;

//checks
long	ft_atol_checker(const char *str);
void	error_exit(t_node *stack_a);
int		check_space(char c);
bool	num_checks(const char *str, t_node *stacks);
void	add_stack(t_stack *stack, int *i, char **argv);

//check_numbers
int		min_number(t_stack *stack);
int		max_number(t_stack *stack);
int		total_steps(t_node *current_a);
int		min_steps(int *steps);

//lst_utils
int		lst_count_num(t_stack *stacks);
void	link_node(t_stack *stack, t_node *new_node);
t_node	*create_stack(int num);
void	free_stack(t_stack *stack);

//debug
void	print_stack(t_stack *stack_a, t_stack *stack_b);

//operation
void	push_swap(t_stack *stack_a, t_stack *stack_b);

//operation_utils
void	swap(t_stack *stack);
void	push(t_stack *stack_from, t_stack *stack_to);
void	reverse_rotate(t_stack *stack);
void	rotate(t_stack *stack);

//operation_utilities
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_node *stack_a, t_node *stack_b);

//sorting
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);

//sorting_utils
void	rank(t_stack *stacks);
void	add_index_to_stack(t_stack *stack);
void	set_every_step_to_zero(t_stack *stack);
void	steps_to_handle_min_max(t_stack *stack_a, t_stack *stack_b);

//sorting_utils2
void	sort_in_between(t_node *current_a, t_stack *stack_b);

//run_steps_utils
void	set_rr_rrr(t_stack *stack_a);
void	run_steps(t_node *current, t_stack *stack_a, t_stack *stack_b);

//count_steps
void	count_steps_to_top_a(t_stack *stack_a);
void	count_steps_to_top_b(t_stack *stack_b, t_node *current_a);
void	set_up_count_rotations(t_stack *stack_a, t_stack *stack_b);
void	count_b_steps(t_node *current_a, t_stack *stack_b, t_node *current_b);

//sort_big
void	lets_sort_decending(t_stack *stack_a, t_stack *stack_b);
void	empty_stack_b(t_stack *stack_a, t_stack *stack_b);

#endif
