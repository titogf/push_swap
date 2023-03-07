/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:22:12 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/07 13:39:11 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_smaller(t_stack *stack);
static void	ft_bigger(t_stack *stack, int aux1, int aux2, int aux3);

void	ft_movements(t_stack *stack, t_nb *nb)
{
	if (nb->arguments < 4)
	{
		if (nb->arguments == 2)
			ft_sa(stack, 1);
		else
			ft_short_mv(stack);
		return ;
	}
	ft_pb(stack);
	ft_pb(stack);
	ft_pb(stack);
	ft_pb(stack);
	ft_pb(stack);
	ft_pb(stack);
	ft_sb(stack, 1);
	ft_rb(stack, 1);
	ft_rrb(stack, 1);
	ft_pa(stack);
	ft_pa(stack);
	ft_pa(stack);
}

void	ft_short_mv(t_stack *stack)
{
	t_lst	*list;
	int		aux1;
	int		aux2;
	int		aux3;

	list = stack->a;
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
		ft_ra(stack, 1);
		order = ft_check_order(stack);
		if (order == 1)
			return ;
	}
	ft_sa(stack, 1);
	order = ft_check_order(stack);
	if (order == 1)
		return ;
	ft_rra(stack, 1);
	order = ft_check_order(stack);
	if (order == 1)
		return ;
	ft_sa(stack, 1);
}

static void	ft_smaller(t_stack *stack)
{
	int	order;

	ft_rra(stack, 1);
	order = ft_check_order(stack);
	if (order == 1)
		return ;
	ft_sa(stack, 1);
}
