/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:44:50 by gfernand          #+#    #+#             */
/*   Updated: 2023/02/20 18:44:23 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_lst
{
	int				content;
	struct s_lst	*next;
}	t_lst;

typedef struct s_stack
{
	t_lst	*a;
	t_lst	*b;
	t_lst	*first_node_a;
	t_lst	*first_node_b;
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
void		ft_sa(t_stack *stack);
void		ft_ra(t_stack *stack);
void		ft_rra(t_stack *stack);

#endif
