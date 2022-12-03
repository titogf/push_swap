/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:42:40 by gfernand          #+#    #+#             */
/*   Updated: 2022/12/01 18:19:12 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_numbers(char **av, int i, int j);

void	ft_repnb(t_nb *nb)
{
	int	i;
	int	j;

	i = -1;
	while (++i < nb->numbers)
	{
		printf("NUMBER= %d\n", nb->n[i]);
		j = i;
		while (++j < nb->numbers)
		{
			if (nb->n[i] == nb->n[j])
				ft_put_finish("Error\n");
		}
	}
}

void	ft_save_nb(int ac, char **av, t_nb *nb)
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
				nb->n[++nb->arr] = ft_atoi(nb->str);
				nb->start = -1;
				free (nb->str);
			}
		}
	}
}

static void	ft_check_numbers(char **av, int i, int j)
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
				nb->numbers++;
			if (j == 0 && av[i][j] == ' ')
				nb->numbers--;
			ft_check_numbers(av, i, j);
		}
		nb->numbers++;
	}
	return (nb->numbers);
}
