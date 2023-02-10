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
static void	ft_merge_sort(int *n, int l, int m, int r);
static void	ft_sort_array(t_sort *sort, int *n, int l, int r);

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
		ft_merge_sort(n, l, m, r);
	}
}

static void	ft_merge_sort(int *n, int l, int m, int r)
{
	t_sort	*sort;
	int		i;

	sort = malloc (sizeof (t_sort));
	sort->l_len = m - l + 1;
	sort->r_len = r - m;
	sort->temp_l = malloc (sizeof (int) * sort->l_len);
	sort->temp_r = malloc (sizeof (int) * sort->r_len);
	i = -1;
	while (++i < sort->l_len)
		sort->temp_l[i] = n[l + i];
	i = -1;
	while (++i < sort->r_len)
		sort->temp_r[i] = n[m + 1 + i];
	ft_sort_array(sort, n, l, r);
	free(sort->temp_l);
	free(sort->temp_r);
	free(sort);
}

static void	ft_sort_array(t_sort *sort, int *n, int l, int r)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = l - 1;
	while (++k <= r)
	{
		if ((i < sort->l_len)
			&& (j >= sort->r_len || sort->temp_l[i] <= sort->temp_r[j]))
		{
			n[k] = sort->temp_l[i];
			i++;
		}
		else
		{
			n[k] = sort->temp_r[j];
			j++;
		}
	}
}

static void	ft_positive(t_nb *nb, int *aux)
{
	int	i;
	int	j;

	i = -1;
	while (++i < nb->arguments)
	{
		j = -1;
		while (++j < nb->arguments)
		{
			if (nb->num[i] == aux[j])
			{
				nb->num[i] = j;
				j = nb->arguments - 2;
			}
		}
	}
}
