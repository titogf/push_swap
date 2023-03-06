/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:42:34 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/06 18:01:54 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack, int n)
{
	int		aux1;
	int		aux2;
	t_lst	*list;

	list = stack->a;
	aux1 = list->content;
	list = list->next;
	aux2 = list->content;
	list->content = aux1;
	list = stack->a;
	list->content = aux2;
	if (n == 1)
		write(1, "sa\n", 3);
	list = stack->a;
	while (list)
	{
		printf("SA--> %d\n", list->content);
		list = list->next;
	}
}
/*
void	ft_pa(t_stack *stack)
{
	t_stack	*aux;

	if (!stack->b)
		return ;
	aux = stack->fitst_node_b;
	stack->b = stack->fist_node_b;
	stack->first_node_b = stack->b->next;
	aux->next = stack->first_node_a;
	stack->first_node_a = aux;
	write(1, "pa\n", 3);
}
*/
void	ft_ra(t_stack *stack, int n)
{
	t_lst	*swap_node;
	t_lst	*list;

	swap_node = stack->a;
	list = stack->a;
	list = list->next;
	stack->a = list;
	while (list->next != NULL)
		list = list->next;
	list->next = swap_node;
	list = list->next;
	list->next = NULL;
	if (n == 1)
		write(1, "ra\n", 3);
	list = stack->a;
	while (list)
	{
		printf("RA----> %d\n", list->content);
		list = list->next;
	}
}

void	ft_rra(t_stack *stack, int n)
{
	t_lst	*aux;
	t_lst	*list;

	list = stack->a;
	while (list->next)
	{
		aux = list;
		list = list->next;
	}
	aux->next = NULL;
	list->next = stack->a;
	stack->a = list;
	if (n == 1)
		write(1, "rra\n", 4);
	while (list)
	{
		printf("RRA----> %d\n", list->content);
		list = list->next;
	}
}
