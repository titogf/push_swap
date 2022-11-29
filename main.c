/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:42:32 by gfernand          #+#    #+#             */
/*   Updated: 2022/11/28 17:11:11 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*static void	leaks()
{
	system("leaks push_swap");
}*/

int	main(int ac, char **av)
{
	//atexit(leaks);
	if (ac < 2)
		exit (1);
	ft_check(ac, av);
	return (0);
}

void	ft_put_finish(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	exit (1);
}
