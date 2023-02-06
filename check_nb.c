/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:42:40 by gfernand          #+#    #+#             */
/*   Updated: 2023/02/06 11:23:25 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_argc(char **av, int i, int j);
static void	ft_repnb(t_nb *nb);

static void	ft_repnb(t_nb *nb)
{
	int	i;
	int	j;

	i = -1;
	while (++i < nb->arguments)
	{
		printf("NUMBER= %d\n", nb->num[i]);
		j = i;
		while (++j < nb->arguments)
		{
			if (nb->num[i] == nb->num[j])
				ft_put_finish("Error\n");
		}
	}
	i = -1;
	while (++i < nb->arguments)
	{
		if ((i + 1) == nb->arguments)
			exit (1);
		if (!(nb->num[i] < nb->num[i + 1]))
			return ;
	}
}

void	ft_check_nb(int ac, char **av, t_nb *nb)
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
	ft_repnb(nb);
}

static void	ft_argc(char **av, int i, int j)
{
	if (av[i][j] < '0' || av[i][j] != ' ')
	{
		if (av[i][j] > '9' && av[i][j] != '-' && av[i][j] != '+')
			ft_put_finish("Error\n");
	}
	if (av[i][j] == '+' || av[i][j] == '-')
	{
		if (!av[i][j + 1])
			ft_put_finish("Error\n");
		else if (av[i][j + 1] < '0' || av[i][j + 1] > '9')
			ft_put_finish("Error\n");
		if (j > 0 && av[i][j - 1] != ' ')
			ft_put_finish("Error\n");
	}
}

void	ft_count(int ac, char **av, t_nb *nb)
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
			ft_argc(av, i, j);
		}
		nb->arguments++;
	}
}
