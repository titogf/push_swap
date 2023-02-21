/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:28:17 by gfernand          #+#    #+#             */
/*   Updated: 2023/02/20 18:24:48 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_stack(t_stack *stack);

void	ft_create_list(t_nb *nb)
{
	t_stack	*stack;
	int		i;

	ft_parse(nb);
	stack = malloc (sizeof (t_stack));
	stack->a = (t_lst *)ft_lstnew(nb->num[0]);
	printf("List-> %d\n", stack->a->content);
	stack->first_node_a = stack->a;
	i = 0;
	while (++i < nb->arguments)
	{
		stack->a->next = (t_lst *)ft_lstnew(nb->num[i]);
		stack->a = stack->a->next;
		printf("List-> %d\n", stack->a->content);
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
	free (stack);
}

int	ft_check_order(t_stack *stack)
{
	t_lst	*aux;
	int		n1;
	int		n2;

	aux = stack->first_node_a;
	while (aux->next)
	{
		n1 = aux->content;
		aux = aux->next;
		n2 = aux->content;
		if (n1 > n2)
			return (-1);
	}
	return (1);
}
