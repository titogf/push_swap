/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:22:12 by gfernand          #+#    #+#             */
/*   Updated: 2023/02/20 16:02:26 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sa(t_stack *stack);
static void	ft_sort_3(t_stack *stack);

void	ft_movements(t_stack *stack, t_nb *nb)
{
	if (nb->arguments < 4)
	{
		if (nb->arguments == 2)
			ft_sa(stack);
		else
			ft_sort_3(stack);
		return ;
	}
}

static void	ft_sa(t_stack *stack)
{
	int	aux1;
	int	aux2;

	stack->a = stack->first_node_a;
	aux1 = stack->a->content;
	stack->a = stack->a->next;
	aux2 = stack->a->content;
	stack->a->content = aux1;
	stack->a = stack->first_node_a;
	stack->a->content = aux2;
	write(1, "sa\n", 3);
/*	while (stack->a)
	{
		printf("SA--> %d\n", stack->a->content);
		stack->a = stack->a->next;
	}*/
}

static void	ft_ra(t_stack *stack)
{
	t_lst	*swap_node;

	swap_node = stack->first_node_a;
	stack->a = stack->first_node_a;
	stack->a = stack->a->next;
	stack->first_node_a = stack->a;
	while (stack->a->next != NULL)
		stack->a = stack->a->next;
	stack->a->next = swap_node;
	stack->a = stack->a->next;
	stack->a->next = NULL;
	write(1, "ra\n", 3);
	stack->a = stack->first_node_a;
	/*while (stack->a)
	{
		printf("RA----> %d\n", stack->a->content);
		stack->a = stack->a->next;
	}*/
}

static void	ft_sort_3(t_stack *stack)
{
	int	aux1;
	int	aux2;

	stack->a = stack->first_node_a;
	if (stack->a->content == 0)
	{
		ft_sa(stack);
		ft_ra(stack);
		return ;
	}
	aux1 = stack->a->content;
	stack->a = stack->a->next;
	aux2 = stack->a->content;
	if (aux1 > aux2)
		ft_sa(stack);
}
