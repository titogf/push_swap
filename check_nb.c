/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:42:40 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/13 17:20:16 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_argc(char **av, int i, int j);
static int	ft_repnb(t_nb *nb);

static int	ft_repnb(t_nb *nb)
{
	int	i;
	int	j;

	i = -1;
	while (++i < nb->arguments)
	{
		j = i;
		while (++j < nb->arguments)
		{
			if (nb->num[i] == nb->num[j])
				return (0);
		}
	}
	i = -1;
	while (++i < nb->arguments)
	{
		if ((i + 1) == nb->arguments)
			return (-1);
		if (!(nb->num[i] < nb->num[i + 1]))
			return (1);
	}
	return (1);
}

int	ft_check_nb(int ac, char **av, t_nb *nb)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			while (nb->start == -1 && av[i][j] == ' ' && av[i][j + 1])
				j++;
			if (nb->start == -1 && av[i][j] != ' ' && av[i][j])
				nb->start = j;
			if (nb->start != -1 && (av[i][j] == ' ' || !av[i][j + 1]))
			{
				nb->len = j - nb->start;
				if (av[i][j] != ' ' && av[i][j + 1] == '\0')
					nb->len++;
				nb->str = ft_substr(av[i], nb->start, nb->len);
				nb->num[++nb->arr] = ft_atoi(nb->str);
				nb->start = -1;
			}
		}
	}
	return (ft_repnb(nb));
}

static int	ft_argc(char **av, int i, int j)
{
	if (av[i][j] < '0' || av[i][j] != ' ')
	{
		if (av[i][j] > '9' && av[i][j] != '-' && av[i][j] != '+')
			return (0);
	}
	if (av[i][j] == '+' || av[i][j] == '-')
	{
		if (!av[i][j + 1])
			return (0);
		else if (av[i][j + 1] < '0' || av[i][j + 1] > '9')
			return (0);
		if (j > 0 && av[i][j - 1] != ' ')
			return (0);
	}
	return (1);
}

int	ft_count(int ac, char **av, t_nb *nb)
{
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{	
			if (av[i][j] == ' ' && av[i][j + 1] != ' ' && av[i][j + 1] != '\0')
				nb->arguments++;
			if (j == 0 && av[i][j] == ' ')
				nb->arguments--;
			if (ft_argc(av, i, j) == 0)
				return (0);
		}
		nb->arguments++;
	}
	return (1);
}
