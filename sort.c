/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:47:49 by gfernand          #+#    #+#             */
/*   Updated: 2023/02/06 15:30:22 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sortest(t_nb *nb, int *aux);

void	ft_sort(t_nb *nb)
{
	int	*aux;
	int	swap;
	int i;
	int j;

	aux = malloc (sizeof (int) * nb->arguments);
	if (!aux)
		exit (2);
	i = -1;
	while (++i < nb->arguments)
		aux[i] = nb->num[i];
	i = -1;
	while (++i < nb->arguments)
	{
		j = i;
		while (j + 1 < nb->arguments && aux[++j])
		{
			if (aux[i] > aux[j])
			{
				swap = aux[i];
				aux[i] = aux[j];
				aux[j] = swap;
			}
		}
	}
	int x = 0;
	while (x < nb->arguments)
		printf("\t-> %d\n", aux[x++]);
	ft_sortest(nb, aux);
}

static void	ft_sortest(t_nb *nb, int *aux)
{
	int	i;
	int	j;

	i = -1;
	while ((i + 1 < nb->arguments) && nb->num[++i])
	{
		j = -1;
		while ((j + 1 < nb->arguments) && aux[++j])
		{
			if (nb->num[i] == aux[j])
			{
				nb->num[i] = j;
				j = nb->arguments - 2;
			}
		}
	}
	free (aux);
}
