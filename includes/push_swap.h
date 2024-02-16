/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:37:59 by djin              #+#    #+#             */
/*   Updated: 2024/02/16 08:55:18 by codespace        ###   ########.fr       */
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

typedef struct s_node
{
	int				num;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;	
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

//lst_utils
int		lst_count_num(t_node *stack);
void 	link_node(t_stack *stack, t_node *new_node);
t_node	*create_stack(int num);
void	free_stack(t_stack *stack);

//debug
void	print_stack(t_stack *stack_a, t_stack *stack_b);

//operation
void	push_swap(t_node **stack_a, t_node **stack_b);

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
void	sort_four(t_node **stack_a, t_node **stack_b);

//sorting_utils
void	rank(t_node *stack_a);

#endif
