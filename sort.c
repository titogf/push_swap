/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:42:34 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/06 16:00:16 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack, int n)
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
	if (n == 1)
		write(1, "sa\n", 3);
	while (stack->a)
	{
		printf("SA--> %d\n", stack->a->content);
		stack->a = stack->a->next;
	}
}
/*
void	ft_pa(t_stack *stack)
{
	if (!stack->b)
		return ;
	stack->b = stack->fitst_node_b;
}
*/
void	ft_ra(t_stack *stack, int n)
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
	if (n == 1)
		write(1, "ra\n", 3);
	stack->a = stack->first_node_a;
	while (stack->a)
	{
		printf("RA----> %d\n", stack->a->content);
		stack->a = stack->a->next;
	}
}

void	ft_rra(t_stack *stack, int n)
{
	t_lst	*aux;

	stack->a = stack->first_node_a;
	while (stack->a->next)
	{
		aux = stack->a;
		stack->a = stack->a->next;
	}
	aux->next = NULL;
	stack->a->next = stack->first_node_a;
	stack->first_node_a = stack->a;
	if (n == 1)
		write(1, "rra\n", 4);
	while (stack->a)
	{
		printf("RRA----> %d\n", stack->a->content);
		stack->a = stack->a->next;
	}
}
