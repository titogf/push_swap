/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:42:06 by gfernand          #+#    #+#             */
/*   Updated: 2022/12/01 17:30:14 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_int(char *str, int i, int nb, int sig);

char	*ft_substr(char	*str, int start, int len)
{
	int		i;
	char	*c;

	c = malloc(sizeof (char *) * len + 1);
	if (!c)
		return (NULL);
	i = 0;
	while (str[start] && i < len)
	{
		c[i] = str[start];
		start++;
		i++;
	}
	c[i] = '\0';
	return (c);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sig;

	if (!str || !str[0])
		return (-1);
	i = 0;
	nb = 0;
	sig = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i])
	{
		nb = nb * 10 + (str[i] - 48);
		ft_max_int(str, i, nb, sig);
		i++;
	}
	return (nb * sig);
}

static int	ft_max_int(char *str, int i, int nb, int sig)
{
	int	m;

	if (nb > 214748364)
	{
		if (str[i + 1])
			ft_put_finish("Error\n");
	}
	if (nb == 214748364 && str[i + 1])
	{
		if (str[i + 2])
			ft_put_finish("Error\n");
		m = (str[++i] - 48);
		if (m > 8)
			ft_put_finish("Error\n");
		else if (m == 8 && sig > 0)
			ft_put_finish("Error\n");
		nb = nb * 10 + (str[i] - 48);
	}
	return (nb);
}
