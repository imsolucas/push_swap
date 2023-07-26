/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djin <djin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:37:59 by djin              #+#    #+#             */
/*   Updated: 2023/07/26 20:49:01 by djin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

//checks
long	ft_atol_checker(const char *str, t_node *stack_a);
void	error_exit(t_node *stack_a);
int		check_space(char c);
int		checks(t_node *stack_a, char *str);

//lst_utils
t_node	*lst_first_last(t_node *node, bool is_last);
void	clear_lst(t_node *node, bool loop);
t_node	*new_node(int content);
t_node	*node_join(t_node *node, int content);

//debug
void	print_stack(t_node *stack_a, t_node *stack_b);

#endif
