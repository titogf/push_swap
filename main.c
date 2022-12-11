/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:42:32 by gfernand          #+#    #+#             */
/*   Updated: 2022/12/05 14:40:54 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_initialise(t_nb *nb);

/*static void	leaks()
{
	system("leaks push_swap");
}*/

int	main(int ac, char **av)
{
	t_nb	*nb;

	//atexit(leaks);
	if (ac < 2)
		exit (1);
	nb = malloc (sizeof (t_nb));
	ft_initialise(nb);
	ft_count(ac, av, nb);
	nb->n = malloc (sizeof (int) * nb->numbers);
	if (!nb->n)
		return (0);
	ft_save_nb(ac, av, nb);
	ft_repnb(nb);
	free (nb->n);
	ft_create_list(nb);
	free (nb);
	return (0);
}

static void	ft_initialise(t_nb *nb)
{
	nb->numbers = 0;
	nb->start = -1;
	nb->arr = -1;
}

void	ft_put_finish(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(2, &c[i], 1);
		i++;
	}
	exit (1);
}
