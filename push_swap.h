/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:37:59 by djin              #+#    #+#             */
/*   Updated: 2024/01/04 21:06:04 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_node
{
	int				num;
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
void	print_stack(t_node *stack_a);

//operation
bool	push(t_node **from, t_node **to);
bool	rotate(t_node **stack, bool reverse);

#endif
