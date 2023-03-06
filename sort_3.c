/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:43:28 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/06 20:08:31 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack *stack)
{
	t_lst	*list_a;
	t_lst	*list_b;
	int		n;

	list_a = stack->a;
	n = -1;
	while (list_a && ++n < 2)
		list_a = list_a->next;
	if (n < 2)
		return ;
	list_b = stack->b;
	n = -1;
	while (list_b && ++n < 2)
		list_b = list_b->next;
	if (n < 2)
		return ;
	ft_sa(stack, 0);
	ft_sb(stack, 0);
	write (1, "ss\n", 3);
}

void	ft_rr(t_stack *stack)
{
	t_lst	*list_a;
	t_lst	*list_b;
	int		n;

	list_a = stack->a;
	n = -1;
	while (list_a && ++n < 2)
		list_a = list_a->next;
	if (n < 2)
		return ;
	list_b = stack->b;
	n = -1;
	while (list_b && ++n < 2)
		list_b = list_b->next;
	if (n < 2)
		return ;
	ft_ra(stack, 0);
	ft_rb(stack, 0);
	write (1, "rr\n", 3);
}

void	ft_rrr(t_stack *stack)
{
	t_lst	*list_a;
	t_lst	*list_b;
	int		n;

	list_a = stack->a;
	n = -1;
	while (list_a && ++n < 2)
		list_a = list_a->next;
	if (n < 2)
		return ;
	list_b = stack->b;
	n = -1;
	while (list_b && ++n < 2)
		list_b = list_b->next;
	if (n < 2)
		return ;
	ft_rra(stack, 0);
	ft_rrb(stack, 0);
	write (1, "rrr\n", 4);
}
