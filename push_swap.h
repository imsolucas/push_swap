/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:37:59 by djin              #+#    #+#             */
/*   Updated: 2024/01/09 16:31:39 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

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

//lst_utils
t_node	*add_stack(t_node *stack, long num);
t_node	*create_stack(int num);
t_node	*stack_go_back(t_node *stack, bool is_last);
void	free_stack(t_node *stack);

//debug
void	print_stack(t_node *stack_a, t_node *stack_b);

//operation
void	swap(t_node **stack);
void	push(t_node **stack_a, t_node **stack_b);
void	reverse_rotate(t_node **stack);
void	rotate(t_node **stack);

#endif
