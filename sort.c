/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:47:49 by gfernand          #+#    #+#             */
/*   Updated: 2023/02/07 16:26:20 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static void	ft_positive(t_nb *nb, int *aux);
void	ft_merge_recursion(int *n, int l, int r);

void	ft_sort(t_nb *nb)
{
	int	*aux;
	int	r;
	int	l;
	int	i;

	aux = malloc (sizeof (int) * nb->arguments);
	if (!aux)
		exit (2);
	i = -1;
	while (++i < nb->arguments)
		aux[i] = nb->num[i];
	l = 0;
	r = nb->arguments - 1;
	ft_merge_recursion(aux, l, r);
}

void	ft_merge_recursion(int *n, int l, int r)
{
	int	m;
	int	i;

	if (l < r)
	{
		m = l + (r - l) / 2;
		ft_merge_recursion(n, l, m);
		ft_merge_recursion(n, m + 1, r);
	}
	i = 0;
	while (n[i++])
		printf("Esto es la n en el sort %d\n", n[i]);
}

/*static void	ft_positive(t_nb *nb, int *aux)
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
}*/
