/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:44:50 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/28 13:52:48 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_nb
{
	int		*n;
	int		i;
	int		len;
	int		start;
	int		numbers;
	char	*str;
}	t_nb;

void		ft_put_finish(char *c);

void		ft_check(int ac, char **av);

char		*ft_substr(char	*str, t_nb nb);
int			ft_atoi(char *str);
#endif
