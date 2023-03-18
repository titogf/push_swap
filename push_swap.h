/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:44:50 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/13 17:26:04 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"

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
	int		count_str;
	char	*str;
}	t_nb;

void		ft_create_list(t_nb *nb);

void		ft_put_finish(char *c, t_nb *nb);

int			ft_check_nb(int ac, char **av, t_nb *nb);
int			ft_count(int ac, char **av, t_nb *nb);
int			ft_parse(t_nb *nb);

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

void		ft_movements(t_stack *stack, t_nb *nb);
void		ft_short_mv(t_stack *stack);
void		ft_medium_mv(t_stack *stack);
void		ft_long_mv(t_stack *stack);
void		ft_far(t_stack *stack, int aux, int point);

void		ft_smaller_3(t_stack *stack);
void		ft_bigger_3(t_stack *stack, int aux1, int aux2, int aux3);
int			ft_check_order(t_list *aux);
int			ft_middle_point(t_list *stack, int find);
int			ft_push_to_stack(t_stack *stack, int turn);

#endif
