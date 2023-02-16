/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:28:17 by gfernand          #+#    #+#             */
/*   Updated: 2023/02/14 16:23:55 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_list(t_lst *list);
static void	ft_free_stack(t_stack *stack);

void	ft_create_list(t_nb *nb)
{
	t_lst	*list;
	t_stack	*stack;
	int		i;

	ft_parse(nb);
	list = (t_lst *)ft_lstnew(nb->num[0]);
	stack = malloc (sizeof (t_stack));
	stack->a = (t_lst *)ft_lstnew(nb->num[0]);
	stack->elem_a = stack->a;
	i = -1;
	while (++i < nb->arguments && stack->a != NULL)
	{
		stack->a->content = nb->num[i];
		if (i < nb->arguments)
			stack->a->next = (t_lst *)ft_lstnew(nb->num[i]);
		printf("List-> %d\n", stack->a->content);
		stack->a = stack->a->next;
	}
	ft_movements(stack, nb);
	ft_free_stack(stack);
	ft_free_list(list);
}

static void	ft_free_list(t_lst *list)
{
	t_lst	*aux;

	aux = list->next;
	free (list);
	list = aux;
	free (list);
}

static void	ft_free_stack(t_stack *stack)
{
	t_lst	*aux;

	stack->a = stack->elem_a;
	while (stack->a)
	{
		aux = stack->a->next;
		free (stack->a);
		stack->a = aux;
	}
}
