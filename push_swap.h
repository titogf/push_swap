/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:44:50 by gfernand          #+#    #+#             */
/*   Updated: 2023/01/25 10:23:20 by gfernand         ###   ########.fr       */
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

typedef struct s_nb
{
	int		arr;
	int		*n;
	int		len;
	int		start;
	int		numbers;
	char	*str;
}	t_nb;

void		ft_create_list(t_nb *nb);

void		ft_put_finish(char *c);

void		ft_repnb(t_nb *nb);
void		ft_save_nb(int ac, char **av, t_nb *nb);
void		ft_count(int ac, char **av, t_nb *nb);

#endif
