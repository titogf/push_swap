/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:28:17 by gfernand          #+#    #+#             */
/*   Updated: 2022/12/29 17:28:32 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	ft_create_list(t_nb *nb)
{
	t_list	*list;
	int		i;

	list = malloc (sizeof (t_list));
	list->next = malloc (sizeof (t_list));
	i = -1;
	while (++i < nb->numbers)
	{
		list->content = nb->n[i];
		list = list->next;
	}
	list->content = '\0';
	return (*list);
}
