/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:28:17 by gfernand          #+#    #+#             */
/*   Updated: 2023/01/23 13:47:31 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	ft_create_list(t_nb *nb)
{
	t_list	*list;
	int		i;

	list = ft_lstnew(nb->n[0]);
	i = -1;
	while (++i < nb->numbers && list != NULL)
	{
		list->content = nb->n[i];
		if ((i + 1) >= nb->numbers)
			list->next = ft_lstnew(nb->n[i]);
		list = list->next;
	}
	list->content = '\0';
	return (*list);
}
