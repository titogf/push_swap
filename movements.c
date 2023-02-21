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

static void	ft_short_mv(t_stack *stack);
static void	ft_arg_3(t_stack *stack);

void	ft_movements(t_stack *stack, t_nb *nb)
{
	if (nb->arguments < 4)
	{
		ft_short_mv(stack);
		return ;
	}
}

static void	ft_short_mv(t_stack *stack)
{
	t_lst	*list;
	int		aux1;
	int		aux2;
	int		order;

	list = stack->first_node_a;
	aux1 = list->content;
	list = list->next;
	aux2 = list->content;
	if (aux1 > aux2)
	{
		ft_sa(stack);
		order = ft_check_order(stack);
		if (order == 1)
			return ;
		ft_rra(stack);
		order = ft_check_order(stack);
		if (order == 1)
			return ;
		ft_sa(stack);
	}
	else
		ft_arg_3(stack);
}

static void	ft_arg_3(t_stack *stack)
{
	int	order;

	ft_rra(stack);
	order = ft_check_order(stack);
	if (order == 1)
		return ;
	ft_sa(stack);
}
