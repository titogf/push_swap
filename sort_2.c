/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:05:16 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/07 13:53:21 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_min_stack_b(t_stack *stack);

static int	ft_min_stack_b(t_stack *stack)
{
	t_lst	*list_b;
	int		n;

	list_b = stack->b;
	n = -1;
	while (++n < 2 && list_b)
		list_b = list_b->next;
	if (n < 2)
		return (0);
	return (1);
}

void	ft_sb(t_stack *stack, int n)
{
	int		aux1;
	int		aux2;
	t_lst	*list;

	if (n == 1)
	{
		n = ft_min_stack_b(stack);
		if (n == 0)
			return ;
	}
	list = stack->b;
	aux1 = list->content;
	list = list->next;
	aux2 = list->content;
	list->content = aux1;
	list = stack->b;
	list->content = aux2;
	if (n == 1)
		write(1, "sb\n", 3);
	list = stack->b;
	while (list)
	{
		printf("SB--> %d\n", list->content);
		list = list->next;
	}
}

void	ft_pb(t_stack *stack)
{
	t_lst	*aux;
	t_lst	*list;

	if (!stack->a)
		return ;
	aux = stack->a;
	list = stack->a;
	stack->a = list->next;
	aux->next = stack->b;
	stack->b = aux;
	write(1, "pb\n", 3);
	list = stack->a;
	while (list)
	{
		printf("STACK_A----> %d\n", list->content);
		list = list->next;
	}
	list = stack->b;
	while (list)
	{
		printf("B_STACK----> %d\n", list->content);
		list = list->next;
	}
}

void	ft_rb(t_stack *stack, int n)
{
	t_lst	*swap_node;
	t_lst	*list;

	if (n == 1)
	{
		n = ft_min_stack_b(stack);
		if (n == 0)
			return ;
	}
	swap_node = stack->b;
	list = stack->b;
	list = list->next;
	stack->b = list;
	while (list->next != NULL)
		list = list->next;
	list->next = swap_node;
	list = list->next;
	list->next = NULL;
	if (n == 1)
		write(1, "rb\n", 3);
	list = stack->b;
	while (list)
	{
		printf("RB----> %d\n", list->content);
		list = list->next;
	}
}

void	ft_rrb(t_stack *stack, int n)
{
	t_lst	*aux;
	t_lst	*list;

	if (n == 1)
	{
		n = ft_min_stack_b(stack);
		if (n == 0)
			return ;
	}
	list = stack->b;
	while (list->next)
	{
		aux = list;
		list = list->next;
	}
	aux->next = NULL;
	list->next = stack->b;
	stack->b = list;
	if (n == 1)
		write(1, "rrb\n", 4);
	while (list)
	{
		printf("RRB----> %d\n", list->content);
		list = list->next;
	}
}
