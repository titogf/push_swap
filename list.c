/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:28:17 by gfernand          #+#    #+#             */
/*   Updated: 2023/01/26 15:42:39 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(t_lst *list, t_lst *dir);

void	ft_create_list(t_nb *nb)
{
	t_lst	*list;
	t_lst	*dir;
	int		i;

	list = (t_lst *)ft_lstnew(nb->num[0]);
	dir = list;
	i = -1;
	while (++i < nb->arguments && list != NULL)
	{
		list->content = nb->num[i];
		if (i < nb->arguments)
			list->next = (t_lst *)ft_lstnew(nb->num[i]);
		printf("List-> %d\n", list->content);
		list = list->next;
	}
	ft_move(list, dir);
}

void	ft_move(t_lst *list, t_lst *dir)
{
	list = dir;
	list = list->next;
	list = list->next;
	list = dir;
	printf("esta es el primer numero %d\n", list->content);
}
