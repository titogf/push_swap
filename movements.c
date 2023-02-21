/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:22:12 by gfernand          #+#    #+#             */
/*   Updated: 2023/02/20 18:48:19 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_3(t_stack *stack);

void	ft_movements(t_stack *stack, t_nb *nb)
{
	if (nb->arguments < 4)
	{
		if (nb->arguments == 2)
			ft_sa(stack);
		else
			ft_sort_3(stack);
	}
}

static void	ft_sort_3(t_stack *stack)
{
	t_lst	*list;
	int		aux1;
	int		aux2;
	int		n;

	list = stack->first_node_a;
	if (list->content == 0)
	{
		ft_rra(stack);
		ft_sa(stack);
		return ;
	}
	aux1 = list->content;
	list = list->next;
	aux2 = list->content;
	if (aux1 > aux2)
	{
		ft_sa(stack);
		n = ft_check_order(stack);
		if (n == 1)
			return ;
		ft_rra(stack);
		n = ft_check_order(stack);
		if (n == 1)
			return ;
		ft_ra(stack);
		
	}
	else
	{
		ft_rra(stack);
		n = ft_check_order(stack);
		if (n == 1)
			return ;
		ft_sa(stack);
	}
}

int	ft_check_order(t_stack *stack)
{
	t_lst	*aux;
	int		n1;
	int		n2;

	aux = stack->first_node_a;
	while (aux->next)
	{
		n1 = aux->content;
		aux = aux->next;
		n2 = aux->content;
		if (n1 > n2)
			return (-1);
	}
	return (1);
}
