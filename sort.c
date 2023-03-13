/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:42:34 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/07 15:52:21 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_min_stack_a(t_stack *stack);

static int	ft_min_stack_a(t_stack *stack)
{
	t_list	*list_a;
	int		n;

	list_a = stack->a;
	n = -1;
	while (++n < 2 && list_a)
		list_a = list_a->next;
	if (n < 2)
		return (0);
	return (1);
}

void	ft_sa(t_stack *stack, int n)
{
	int		aux1;
	int		aux2;
	t_list	*list;

	if (n == 1)
	{
		n = ft_min_stack_a(stack);
		if (n == 0)
			return ;
	}
	list = stack->a;
	aux1 = list->content;
	list = list->next;
	aux2 = list->content;
	list->content = aux1;
	list = stack->a;
	list->content = aux2;
	if (n == 1)
		write(1, "sa\n", 3);
}

void	ft_pa(t_stack *stack)
{
	t_list	*aux;
	t_list	*list;

	if (!stack->b)
		return ;
	aux = stack->b;
	list = stack->b;
	stack->b = list->next;
	aux->next = stack->a;
	stack->a = aux;
	write(1, "pa\n", 3);
}

void	ft_ra(t_stack *stack, int n)
{
	t_list	*swap_node;
	t_list	*list;

	if (n == 1)
	{
		n = ft_min_stack_a(stack);
		if (n == 0)
			return ;
	}
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
}

void	ft_rra(t_stack *stack, int n)
{
	t_list	*aux;
	t_list	*list;

	if (n == 1)
	{
		n = ft_min_stack_a(stack);
		if (n == 0)
			return ;
	}
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
}
