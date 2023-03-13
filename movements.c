/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:22:12 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/13 16:25:23 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_movements(t_stack *stack, t_nb *nb)
{
	t_list	*list;

	if (nb->arguments <= 3)
		ft_short_mv(stack);
	if (nb->arguments <= 5)
		ft_medium_mv(stack);
	list = stack->a;
	while (list)
	{
		printf("FIN -- %d\n", list->content);
		list = list->next;
	}
}

void	ft_short_mv(t_stack *stack)
{
	t_list	*list;
	int		aux1;
	int		aux2;
	int		aux3;

	list = stack->a;
	aux1 = list->content;
	list = list->next;
	aux2 = list->content;
	if (!list->next)
	{
		ft_sa(stack, 1);
		return ;
	}
	list = list->next;
	aux3 = list->content;
	if (aux1 > aux2)
		ft_bigger_3(stack, aux1, aux2, aux3);
	else
		ft_smaller_3(stack);
}

void	ft_medium_mv(t_stack *stack)
{
	t_list	*list;
	int		aux;
	int		point;

	list = stack->a;
	aux = list->content;
	while (list->next)
	{
		list = list->next;
		if (list->content < aux)
			aux = list->content;
	}
	point = ft_middle_point(stack->a, aux);
	if (point == 1)
		ft_far(stack, aux, point);
	else if (point == 2)
		ft_far(stack, aux, point);
}
