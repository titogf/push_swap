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

int	ft_middle_point(t_list *stack, int find);
void	ft_medium_mv(t_stack *stack);

void	ft_movements(t_stack *stack, t_nb *nb)
{
	if (nb->arguments <= 3)
		ft_short_mv(stack);
	if (nb->arguments <= 5)
		ft_medium_mv(stack);
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
	int	aux;

	list = stack->a;
	aux = list->content;
	while (list->next)
	{
		list = list->next;
		if (list->content < aux)
			aux = list->content;
	}
	list = stack->a;
	if (ft_middle_point(stack->a, aux) == 1)
	{
		while (list->content != aux)
		{
			ft_ra(stack, 1);
			list = stack->a;
		}
		ft_check_order(stack->a);
	}
	else
	{
		while (list->content != aux)
		{
			ft_rra(stack, 1);
			list = stack->a;
		}
	}
}

int	ft_middle_point(t_list *stack, int find)
{
	t_list	*list;
	int		middle;
	int		size;
	int		count;

	list = stack;
	size = ft_lstsize(list);
	middle = (size / 2) + 1;
	count = 1;
	while (list)
	{
		if (list->content == find)
		{
			if (count <= middle)
				return (1);
			else
				return (2);
		}
		list = list->next;
		count++;
	}
	return (0);
}
