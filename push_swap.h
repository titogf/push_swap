/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:44:50 by gfernand          #+#    #+#             */
/*   Updated: 2022/12/01 17:28:06 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_nb
{
	int		arr;
	int		*n;
	int		len;
	int		start;
	int		numbers;
	char	*str;
}	t_nb;

void		ft_put_finish(char *c);

void		ft_repnb(t_nb *nb);
void		ft_save_nb(int ac, char **av, t_nb *nb);
int		ft_count(int ac, char **av, t_nb *nb);

char		*ft_substr(char	*str, int start, int len);
int			ft_atoi(char *str);
#endif
