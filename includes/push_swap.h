/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:37:59 by djin              #+#    #+#             */
/*   Updated: 2024/04/03 19:16:43 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 100
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
	int	size;
	int	half_of_size;
	int	index;
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
void	error_exit(char *str);
bool	num_checks(char *str);
void	add_stack(t_stack *stack, int *i, char **argv, int argc);
void	print_stack(t_stack *a, t_stack *b, t_node *tmp_a, t_node *tmp_b);

//checks2
bool	check_space(char c);
void	error_free_exit(char *str, t_stack *stack_a, int argc, char **argv);
void	is_num_dup(t_stack *stack_a, int argc, char **argv);
bool	only_one_num(t_stack *stack_a);
void	free_argv(char **argv);

//checks3
bool	is_sorted(t_stack *stack);
void	check_errors(t_stack *stack_a, int argc, char **argv);

//check_numbers
int		min_number(t_stack *stack);
int		max_number(t_stack *stack);
int		total_steps(t_node *current_a);
int		min_steps_index(int *steps, t_size *sort);
int		max_number_index(t_stack *stack);

//lst_utils
int		lst_count_num(t_stack *stacks);
void	link_node(t_stack *stack, t_node *new_node);
t_node	*create_stack(int num);
void	free_stack(t_stack *stack);

//operation
void	push_swap(t_stack *stack_a, t_stack *stack_b);

//operation_utils
void	swap(t_stack *stack);
void	push(t_stack *stack_from, t_stack *stack_to);
void	reverse_rotate(t_stack *stack);
void	rotate(t_stack *stack);

//operation_utilities
void	sa(t_stack *stack, bool print);
void	sb(t_stack *stack, bool print);
void	ss(t_stack *stack_a, t_stack *stack_b, bool print);
void	pa(t_stack *stack_a, t_stack *stack_b, bool print);
void	pb(t_stack *stack_a, t_stack *stack_b, bool print);
void	ra(t_stack *stack, bool print);
void	rb(t_stack *stack, bool print);
void	rr(t_stack *stack_a, t_stack *stack_b, bool print);
void	rra(t_stack *stack, bool print);
void	rrb(t_stack *stack, bool print);
void	rrr(t_stack *stack_a, t_stack *stack_b, bool print);

//sorting
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	sort_big(t_stack *stack_a, t_stack *stack_b);

//sorting_utils
void	rank(t_stack *stacks);
void	add_index_to_stack(t_stack *stack);
void	set_every_step_to_zero(t_stack *stack);
void	steps_to_handle_min_max(t_stack *stack_a, t_stack *stack_b);

//sorting_utils2
void	sort_in_between(t_node *current_a, t_stack *stack_b);
void	sort_out_between(t_node *current_a, t_stack *stack_b);

//run_steps_utils
void	set_rr_rrr(t_stack *stack_a);
void	run_steps(t_node *current, t_stack *stack_a, t_stack *stack_b);

//count_steps
void	count_steps_to_top_a(t_stack *stack_a);
void	max_steps_to_top_b(t_node *current_a, t_stack *stack_b);
void	count_b_steps(t_node *current_a, t_stack *stack_b, t_node *current_b);

//lets_sort_decending
void	set_up_count_rotations(t_stack *stack_a, t_stack *stack_b);

//lets_sort_acending
void	set_down_count_rotations(t_stack *stack_a, t_stack *stack_b);

//sort_big
void	lets_sort_decending(t_stack *stack_a, t_stack *stack_b);
void	lets_sort_acending(t_stack *stack_a, t_stack *stack_b);
void	empty_stack_b(t_stack *stack_a, t_stack *stack_b);

//sort_decending
void	sort_decending(t_stack *stack_b);

//sort_big_utils
void	sorting(t_stack *stack_a, t_stack *stack_b, int *steps, t_size *sort);

// get next line
char	*get_next_line(int fd);

// checker
void	check_input(t_stack *a, t_stack *b);

// checker utils
bool	is_valid(char *str);
void	error_input(char *str, char *input);
bool	not_empty(t_stack *stack_b);
bool	is_not_sorted(t_stack *stack_a);
void	sort(t_stack *stack_a, t_stack *stack_b, char *str);

#endif
