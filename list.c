/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:28:17 by gfernand          #+#    #+#             */
/*   Updated: 2023/01/26 12:19:19 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	ft_create_list(t_nb *nb)
{
	t_lst	*list;
	void	*dir;
	int		i;

	list = (t_lst *)ft_lstnew(nb->n[0]);
	dir = &list;
	printf("DIR = %p\n", dir);
	i = -1;
	printf("LIST:\n");
	while (++i < nb->numbers && list != NULL)
	{
		list->content = nb->n[i];
		if (i < nb->numbers)
			list->next = (t_lst *)ft_lstnew(nb->n[i]);
		printf(" %d\n", list->content);
		list = list->next;
	}
	list = dir;
	printf(" %d\n", list->content);
	return (*list);
}
