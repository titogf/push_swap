/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 12:23:49 by gfernand          #+#    #+#             */
/*   Updated: 2022/02/01 11:41:42 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char	*str, int start, int len)
{
	int		i;
	char	*c;

	if (len == 0)
		len++;
	c = malloc(sizeof (char *) * len + 1);
	if (!c)
		return (NULL);
	i = 0;
	while (str[start] && i < len)
	{
		c[i] = str[start];
		start++;
		i++;
	}
	c[i] = '\0';
	return (c);
}
