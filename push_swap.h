/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:44:50 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/13 15:25:59 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
/*
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;
*/
typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
}	t_stack;

typedef struct s_sort
{
	int	l_len;
	int	r_len;
	int	*temp_l;
	int	*temp_r;
}	t_sort;

typedef struct s_nb
{
	int		arr;
	int		*num;
	int		len;
	int		start;
	int		arguments;
	char	*str;
}	t_nb;

void		ft_create_list(t_nb *nb);

void		ft_put_finish(char *c);

void		ft_check_nb(int ac, char **av, t_nb *nb);
void		ft_count(int ac, char **av, t_nb *nb);

void		ft_parse(t_nb *nb);

void		ft_movements(t_stack *stack, t_nb *nb);
void		ft_short_mv(t_stack *stack);

void		ft_sa(t_stack *stack, int n);
void		ft_ra(t_stack *stack, int n);
void		ft_rra(t_stack *stack, int n);
void		ft_pa(t_stack *stack);

void		ft_sb(t_stack *stack, int n);
void		ft_rb(t_stack *stack, int n);
void		ft_rrb(t_stack *stack, int n);
void		ft_pb(t_stack *stack);

void		ft_ss(t_stack *stack);
void		ft_rr(t_stack *stack);
void		ft_rrr(t_stack *stack);

int			ft_check_order(t_stack *stack);

void		ft_smaller_3(t_stack *stack);
void		ft_bigger_3(t_stack *stack, int aux1, int aux2, int aux3);

#endif
