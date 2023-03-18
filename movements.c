/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:22:12 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/14 14:49:00 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_int(t_stack *stack);

void	ft_movements(t_stack *stack, t_nb *nb)
{
	//t_list	*list;

	if (nb->arguments <= 3)
		ft_short_mv(stack);
	else if (nb->arguments <= 50)
		ft_medium_mv(stack);
	else
		ft_long_mv(stack);
	/*list = stack->a;
	while (list)
	{
		printf("FIN -- %d\n", list->content);
		list = list->next;
	}*/
}

void	ft_short_mv(t_stack *stack)
{
	t_list	*list;
	int		aux1;
	int		aux2;
	int		aux3;

	list = stack->a;
	aux1 = list->content;
	list = list->next;
	aux2 = list->content;
	if (!list->next)
	{
		ft_sa(stack, 1);
		return ;
	}
	list = list->next;
	aux3 = list->content;
	if (aux1 > aux2)
		ft_bigger_3(stack, aux1, aux2, aux3);
	else
		ft_smaller_3(stack);
}

void	ft_medium_mv(t_stack *stack)
{
	t_list	*list;
	int		aux;
	int		point;

	list = stack->a;
	aux = list->content;
	while (list->next)
	{
		list = list->next;
		if (list->content < aux)
			aux = list->content;
	}
	point = ft_middle_point(stack->a, aux);
	if (point == 1)
		ft_far(stack, aux, point);
	else if (point == 2)
		ft_far(stack, aux, point);
}

void	ft_long_mv(t_stack *stack)
{
	t_list	*list;
	int		i;
	int		j;
	int		max_nb;
	int		max_bits;

	max_nb = ft_max_int(stack);
	max_bits = 0;
	while ((max_nb >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		list = stack->a;
		j = -1;
		while (++j < (max_nb + 1) && list)
		{
			if (((list->content >> i) & 1) == 0)
				ft_pb(stack);
			else if (((list->content >> i) & 1) == 1)
				ft_ra(stack, 1);
			list = stack->a;
		}
		ft_push_to_stack(stack, 2);
	}
}

int	ft_max_int(t_stack *stack)
{
	t_list	*list;
	int		max;

	list = stack->a;
	max = 0;
	while (list)
	{
		if (list->content > max)
			max = list->content;
		list = list->next;
	}
	return (max);
}
