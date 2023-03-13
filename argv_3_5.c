/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:33:02 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/13 13:55:53 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_smaller_3(t_stack *stack)
{
	ft_rra(stack, 1);
	if (ft_check_order(stack->a) == 1)
		return ;
	ft_sa(stack, 1);
}

void	ft_bigger_3(t_stack *stack, int aux1, int aux2, int aux3)
{
	if (aux3 > aux2 && aux3 < aux1)
	{
		ft_ra(stack, 1);
		if (ft_check_order(stack->a) == 1)
			return ;
	}
	ft_sa(stack, 1);
	if (ft_check_order(stack->a) == 1)
		return ;
	ft_rra(stack, 1);
	if (ft_check_order(stack->a) == 1)
		return ;
	ft_sa(stack, 1);
}

void	ft_far(t_stack *stack, int aux, int point)
{
	t_list	*list;

	if (ft_push_to_stack(stack, 1) == 0)
		return ;
	list = stack->a;
	while (list->content != aux)
	{
		if (point == 1)
			ft_ra(stack, 1);
		else if (point == 2)
			ft_rra(stack, 1);
		list = stack->a;
	}
	if (ft_check_order(stack->a) == 1)
	{
		ft_push_to_stack(stack, 2);
		return ;
	}
	else
	{
		ft_pb(stack);
		ft_medium_mv(stack);
	}
}

int	ft_push_to_stack(t_stack *stack, int turn)
{
	t_list	*list;
	t_list	*list_b;

	if (turn == 1)
	{
		list = stack->a;
		if (ft_lstsize(list) < 4)
		{
			ft_short_mv(stack);
			turn = 2;
		}
	}
	if (turn == 2)
	{
		list_b = stack->b;
		while (list_b)
		{
			ft_pa(stack);
			list_b = stack->b;
		}
		return (0);
	}
	return (1);
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
