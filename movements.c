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

static void	ft_smaller(t_stack *stack);
static void	ft_bigger(t_stack *stack, int aux1, int aux2, int aux3);

void	ft_movements(t_stack *stack, t_nb *nb)
{
	if (nb->arguments < 4)
	{
		ft_short_mv(stack);
		return ;
	}
}

void	ft_short_mv(t_stack *stack)
{
	t_lst	*list;
	int		aux1;
	int		aux2;
	int		aux3;

	list = stack->first_node_a;
	aux1 = list->content;
	list = list->next;
	aux2 = list->content;
	list = list->next;
	aux3 = list->content;
	if (aux1 > aux2)
		ft_bigger(stack, aux1, aux2, aux3);
	else
		ft_smaller(stack);
}

static void	ft_bigger(t_stack *stack, int aux1, int aux2, int aux3)
{
	int	order;

	if (aux3 > aux2 && aux3 < aux1)
	{
		ft_ra(stack);
		order = ft_check_order(stack);
		if (order == 1)
			return ;
	}
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

static void	ft_smaller(t_stack *stack)
{
	int	order;

	ft_rra(stack);
	order = ft_check_order(stack);
	if (order == 1)
		return ;
	ft_sa(stack);
}
