/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:05:16 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/06 18:04:08 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_stack *stack, int n)
{
	int		aux1;
	int		aux2;
	t_lst	*list;

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
/*
void	ft_pb(t_stack *stack)
{
	t_stack	*aux;

	if (!stack->b)
		return ;
	aux = stack->fitst_node_b;
	stack->b = stack->fist_node_b;
	stack->first_node_b = stack->b->next;
	aux->next = stack->first_node_a;
	stack->first_node_a = aux;
	write(1, "pb\n", 3);
}
*/
void	ft_rb(t_stack *stack, int n)
{
	t_lst	*swap_node;
	t_lst	*list;

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
		write(1, "ra\n", 3);
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
