/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:43:28 by gfernand          #+#    #+#             */
/*   Updated: 2023/03/06 18:50:26 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack *stack)
{
	if (!(stack->a || stack->b))
		return ;
	else
	{
		ft_sa(stack, 0);
		ft_sb(stack, 0);
		write (1, "ss\n", 3);
	}
}

void	ft_rr(t_stack *stack)
{
	if (!(stack->a || stack->b))
		return ;
	else
	{
		ft_ra(stack, 0);
		ft_rb(stack, 0);
		write (1, "rr\n", 3);
	}
}

void	ft_rrr(t_stack *stack)
{
	if (!(stack->a || stack->b))
		return ;
	else
	{
		ft_rra(stack, 0);
		ft_rrb(stack, 0);
		write (1, "rrr\n", 4);
	}
}
