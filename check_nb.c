/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:42:40 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/28 18:15:08 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_save_nb(int ac, char **av, t_nb nb);
static void	ft_check_numbers(char **av, int i, int j);
/*static void	ft_repnb(t_nb nb);

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
}*/

static void	ft_save_nb(int ac, char **av, t_nb nb)
{
	int		i;
	int		lenc;
	int		lenv;
	char	*str;

	i = -1;
	lenc = 0;
	while (++lenc < ac)
	{
		lenv = -1;
		nb.start = -1;
		while (av[lenc][++lenv])
		{
			while (nb.start == -1 && av[lenc][lenv] == ' ')
				lenv++;
			if (!av[lenc][lenv] && lenc >= ac)
				exit (1);
			if (nb.start == -1 && av[lenc][lenv] != ' ')
				nb.start = lenv;
			if (av[lenc][lenv] == ' ' || av[lenc][lenv + 1] == '\0')
			{
				nb.len = lenv - nb.start;
				if (nb.len == 0 || av[lenc][lenv + 1] == '\0')
					nb.len++;
				if (av[lenc][lenv] == ' ' && av[lenc][lenv + 1] == '\0')
					nb.len--;
				str = ft_substr(av[lenc], nb.start, nb.len);
				nb.n[++i] = ft_atoi(str);
				printf("START AND LEN->%d , %d\n", nb.start, nb.len);
				printf("   STR->%s\n", str);
				printf("   NB= %d\n", nb.n[i]);
				nb.start = -1;
				free (str);
			}
			if (!av[lenc][lenv])
				lenv--;
		}
	}
}

static void	ft_check_numbers(char **av, int i, int j)
{
	if (av[i][j] < '0' || av[i][j] != ' ')
	{
		if (av[i][j] > '9' && av[i][j] != '-' && av[i][j] != '+')
			exit (1);
	}
	if (av[i][j] == '+' || av[i][j] == '-')
	{
		if (!av[i][j + 1])
			ft_put_finish("Error");
		else if (av[i][j + 1] < '0' || av[i][j + 1] > '9')
			ft_put_finish("Error");
		if (j > 0 && av[i][j - 1] != ' ')
			ft_put_finish("Error");
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
			ft_check_numbers(av, i, j);
		}
		nb.numbers++;
	}
	printf("   NB= %d\n", nb.numbers);
	nb.n = malloc (sizeof (int) * nb.numbers);
	ft_save_nb(ac, av, nb);
	//ft_repnb(nb);
	free (nb.n);
}
