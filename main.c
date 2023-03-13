/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:42:32 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/13 17:24:33 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_initialise(t_nb *nb);

static void	leaks()
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_nb	*nb;
	int		check;

	atexit(leaks);
	if (ac < 2)
		return (0);
	nb = malloc (sizeof (t_nb));
	ft_initialise(nb);
	if (ft_count(ac, av, nb) == 0)
	{
		free (nb);
		ft_put_finish("Error\n");
	}
	nb->num = malloc (sizeof (int) * nb->arguments);
	if (!nb->num)
		return (0);
	check = ft_check_nb(ac, av, nb);
	if (check == 0 || check == -1)
	{
		if (check == 0)
		{
			free (nb->num);
			free (nb);
			ft_put_finish("Error\n");
		}
		free (nb->num);
		free (nb);
		return (0);
	}
	ft_create_list(nb);
	return (0);
}

static void	ft_initialise(t_nb *nb)
{
	nb->arguments = 0;
	nb->start = -1;
	nb->arr = -1;
}

void	ft_put_finish(char *c)
{
	int	i;

	i = -1;
	while (c[++i])
		write(2, &c[i], 1);
	exit (1);
}
