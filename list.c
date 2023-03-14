/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:28:17 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/14 14:49:18 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free_stack(t_stack *stack, t_nb *nb);

void	ft_create_list(t_nb *nb)
{
	t_stack	*stack;
	t_list	*first_node;
	int		i;

	if (ft_parse(nb) == 0)
		return ;
	stack = malloc (sizeof (t_stack));
	stack->a = (t_list *)ft_lstnew(nb->num[0]);
//	printf("List-> %d\n", stack->a->content);
	first_node = stack->a;
	i = 0;
	while (++i < nb->arguments)
	{
		stack->a->next = (t_list *)ft_lstnew(nb->num[i]);
		stack->a = stack->a->next;
//		printf("List-> %d\n", stack->a->content);
	}
	stack->a = first_node;
	stack->b = NULL;
	ft_movements(stack, nb);
	ft_free_stack(stack, nb);
}

static void	ft_free_stack(t_stack *stack, t_nb *nb)
{
	t_list	*aux;

	while (stack->a)
	{
		aux = stack->a->next;
		free (stack->a);
		stack->a = aux;
	}
	free (stack);
	free (nb->num);
	free (nb);
}

int	ft_check_order(t_list *list)
{
	t_list	*aux;
	int		n1;
	int		n2;

	aux = list;
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
