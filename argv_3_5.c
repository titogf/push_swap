/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_3_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:33:02 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/13 13:55:53 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bigger_3(t_stack *stack, int aux1, int aux2, int aux3)
{
	int	order;

	if (aux3 > aux2 && aux3 < aux1)
	{
		ft_ra(stack, 1);
		order = ft_check_order(stack);
		if (order == 1)
			return ;
	}
	ft_sa(stack, 1);
	order = ft_check_order(stack);
	if (order == 1)
		return ;
	ft_rra(stack, 1);
	order = ft_check_order(stack);
	if (order == 1)
		return ;
	ft_sa(stack, 1);
}

void	ft_smaller_3(t_stack *stack)
{
	int	order;

	ft_rra(stack, 1);
	order = ft_check_order(stack);
	if (order == 1)
		return ;
	ft_sa(stack, 1);
}
