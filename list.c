/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:28:17 by gfernand          #+#    #+#             */
/*   Updated: 2023/02/20 16:12:27 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_stack(t_stack *stack);

void	ft_create_list(t_nb *nb)
{
	t_stack	*stack;
	t_lst	*pr;
	int		i;

	ft_parse(nb);
	stack = malloc (sizeof (t_stack));
	stack->a = (t_lst *)ft_lstnew(nb->num[0]);
	stack->first_node_a = stack->a;
	i = -1;
	while (++i < nb->arguments && stack->a != NULL)
	{
		stack->a->content = nb->num[i];
		stack->a->next = (t_lst *)ft_lstnew(nb->num[i]);
		printf("List-> %d\n", stack->a->content);
		stack->a = stack->a->next;
	}
	pr = stack->first_node_a;
	while (pr)
	{
		printf("HOLA%d\n", pr->content);
		pr = pr->next;
	}
	ft_movements(stack, nb);
	ft_free_stack(stack);
}

static void	ft_free_stack(t_stack *stack)
{
	t_lst	*aux;

	stack->a = stack->first_node_a;
	while (stack->a)
	{
		aux = stack->a->next;
		free (stack->a);
		stack->a = aux;
	}
}
