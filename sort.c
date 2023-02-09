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


static void	ft_positive(t_nb *nb, int *aux);
static void	ft_merge_recursion(int *n, int l, int r);
static void	ft_sort_array(int *n, int l, int m, int r);

void	ft_sort(t_nb *nb)
{
	int	*aux;
	int	i;

	aux = malloc (sizeof (int) * nb->arguments);
	if (!aux)
		exit (2);
	i = -1;
	while (++i < nb->arguments)
		aux[i] = nb->num[i];
	ft_merge_recursion(aux, 0, nb->arguments - 1);
	i = -1;
	while (++i < nb->arguments)
		printf("AUX\t%d\n", aux[i]);
	ft_positive(nb, aux);
	free(aux);
}

static void	ft_merge_recursion(int *n, int l, int r)
{
	int	m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		ft_merge_recursion(n, l, m);
		ft_merge_recursion(n, m + 1, r);
		ft_sort_array(n, l, m, r);
	}
}

static void	ft_sort_array(int *n, int l, int m, int r)
{
	int	l_len;
	int	r_len;
	int	*temp_l;
	int	*temp_r;
	int	i;
	int	j;
	int	k;

	l_len = m - l + 1;
	r_len = r - m;
	temp_l = malloc (sizeof (int) * l_len);
	temp_r = malloc (sizeof (int) * r_len);
	i = -1;
	while (++i < l_len)
		temp_l[i] = n[l + i];
	i = -1;
	while (++i < r_len)
		temp_r[i] = n[m + 1 + i];
	i = 0;
	j = 0;
	k = l - 1;
	while (++k <= r)
	{
		if ((i < l_len) && (j >= r_len || temp_l[i] <= temp_r[j]))
		{
			n[k] = temp_l[i];
			i++;
		}
		else
		{
			n[k] = temp_r[j];
			j++;
		}
	}
	free(temp_l);
	free(temp_r);
}

static void	ft_positive(t_nb *nb, int *aux)
{
	int	i;
	int	j;

	i = -1;
	while ((i + 1 < nb->arguments) && (nb->num[++i] || nb->num[i] == '0'))
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
}
