/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:05:16 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/06 16:01:31 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_stack *stack, int n)
{
	int	aux1;
	int	aux2;

	stack->b = stack->first_node_b;
	aux1 = stack->b->content;
	stack->b = stack->b->next;
	aux2 = stack->b->content;
	stack->b->content = aux1;
	stack->b = stack->first_node_b;
	stack->b->content = aux2;
	if (n == 1)
		write(1, "sb\n", 3);
	while (stack->b)
	{
		printf("SB--> %d\n", stack->b->content);
		stack->b = stack->b->next;
	}
}

void	ft_rb(t_stack *stack, int n)
{
	t_lst	*swap_node;

	swap_node = stack->first_node_b;
	stack->b = stack->first_node_b;
	stack->b = stack->b->next;
	stack->first_node_b = stack->b;
	while (stack->b->next != NULL)
		stack->b = stack->b->next;
	stack->b->next = swap_node;
	stack->b = stack->b->next;
	stack->b->next = NULL;
	if (n == 1)
		write(1, "rb\n", 3);
	stack->a = stack->first_node_b;
	while (stack->b)
	{
		printf("RB----> %d\n", stack->b->content);
		stack->b = stack->b->next;
	}
}

void	ft_rrb(t_stack *stack, int n)
{
	t_lst	*aux;

	stack->b = stack->first_node_b;
	while (stack->b->next)
	{
		aux = stack->b;
		stack->b = stack->b->next;
	}
	aux->next = NULL;
	stack->b->next = stack->first_node_b;
	stack->first_node_b = stack->b;
	if (n == 1)
		write(1, "rrb\n", 4);
	while (stack->b)
	{
		printf("RRB----> %d\n", stack->b->content);
		stack->b = stack->b->next;
	}
}
