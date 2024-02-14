/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:37:59 by djin              #+#    #+#             */
/*   Updated: 2024/02/14 15:41:18 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int				num;
	struct s_node	*head;
	struct s_node	*tail;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

//checks
long	ft_atol_checker(const char *str);
void	error_exit(t_node *stack_a);
int		check_space(char c);
bool	num_checks(const char *str, t_node *stacks);
void	add_node(t_node **stack, int *i, t_node **head, char **argv);

//lst_utils
t_node	*add_stack(t_node *stack, long num);
t_node	*create_stack(int num);
t_node	*stack_go_back(t_node *stack, bool is_last);
void	free_stack(t_node *stack);

//debug
void	print_stack(t_node *stack_a, t_node *stack_b);

//operation
void	push_swap(t_node **stack_a, t_node **stack_b);

//operation_utils
void	swap(t_node **stack);
void	push(t_node **stack_from, t_node **stack_to);
void	reverse_rotate(t_node **stack);
void	rotate(t_node **stack);

//operation_utilities
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

#endif
