/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:42:40 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/28 14:13:56 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_check_numbers(int ac, char **av, t_nb nb);
static void	ft_repnb(t_nb nb);

static void	ft_repnb(t_nb nb)
{
	int	i;
	int	j;

	i = -1;
	while (nb.n[++i])
	{
		j = i;
		while (nb.n[++j])
		{
			if (nb.n[i] == nb.n[j])
				ft_put_finish("Error");
		}
	}
}

static void	ft_check_numbers(int ac, char **av, t_nb nb)
{
	int	yc;
	int	jv;

	nb.n = malloc (sizeof (int) * nb.numbers);
	nb.i = -1;
	yc = 0;
	while (++yc < ac)
	{
		jv = -1;
		nb.start = -1;
		while (av[yc][++jv])
		{
			while (nb.start == -1 && av[yc][jv] == ' ')
				jv++;
			if (av[yc][jv] == '+' || av[yc][jv] == '-')
			{
				if (av[yc][jv + 1] < '0' || av[yc][jv + 1] > '9')
					ft_put_finish("Error");
				if (jv > 0 && av[yc][jv - 1] != ' ')
					ft_put_finish("Error");
			}
			if (nb.start == -1 && av[yc][jv] != ' ')
				nb.start = jv;
			if (av[yc][jv] == ' ' || av[yc][jv + 1] == '\0')
			{
				nb.len = jv - nb.start;
				if (nb.len == 0 || av[yc][jv + 1] == '\0')
					nb.len++;
				nb.str = ft_substr(av[jv], nb);
				nb.n[++nb.i] = ft_atoi(nb.str);
				printf("%d --- %d\n", nb.start, nb.len);
				printf("%d\n", nb.n[nb.i]);
				nb.start = -1;
			}
		}
	}
}

void	ft_check(int ac, char **av)
{
	t_nb	nb;
	int		i;
	int		j;

	i = 0;
	nb.numbers = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{	
			if (av[i][j] == ' ' && av[i][j + 1] != ' ' && av[i][j + 1] != '\0')
				nb.numbers++;
			if (j == 0 && av[i][j] == ' ')
				nb.numbers--;
			if (av[i][j] < '0' || av[i][j] != ' ')
			{
				if (av[i][j] > '9' && av[i][j] != '-' && av[i][j] != '+')
					exit (1);
			}
		}
		nb.numbers++;
	}
	ft_check_numbers(ac, av, nb);
	ft_repnb(nb);
}
