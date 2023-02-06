/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:47:49 by gfernand          #+#    #+#             */
/*   Updated: 2023/02/06 13:00:34 by gfernand         ###   ########.fr       */
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
	printf("%d", nb->arguments);
	i = -1;
	while (++i < nb->arguments)
		aux[i] = nb->num[i];
	i = -1;
	while (++i < nb->arguments)
	{
		j = i;
		while (aux[++j])
		{
			if (aux[i] > aux[j])
			{
				swap = aux[i];
				aux[i] = aux[j];
				aux[j] = swap;
			}
		}
	}
	ft_sortest(nb, aux);
}

static void	ft_sortest(t_nb *nb, int *aux)
{
	int	i;
	int	j;

	i = -1;
	while (aux[++i])
	{
		j = -1;
		while (nb->num[++j])
		{
			if (nb->num[j] == aux[i])
				nb->num[j] = i;
		}
	}
	free (aux);
}
