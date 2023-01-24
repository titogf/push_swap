/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:53:34 by gfernand          #+#    #+#             */
/*   Updated: 2023/01/23 13:41:56 by gfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ftcount(char const *s, char c);
static char		**ft_site(char **str, char const *s, char c);
static char		**ft_free(char **str);

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**str;

	count = ftcount(s, c);
	str = (char **)malloc(sizeof(char *) *(count + 1));
	if (!str)
		return (NULL);
	ft_site(str, s, c);
	return (str);
}

static	size_t	ftcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i +1])
			count++;
		i++;
	}
	if (s[0] == c || s[0] == '\0')
		count--;
	return (count);
}

static	char	**ft_site(char **str, char const *s, char c)
{
	size_t	i;
	size_t	found;
	size_t	count;
	size_t	start;

	i = 0;
	found = 1;
	count = ftcount(s, c);
	while (found <= count)
	{
		if (s[i] != c)
		{
			start = i++;
			while (s[i] != c && s[i])
				i++;
			str[found - 1] = ft_substr((char *)s, start, (i - 1) - start + 1);
			if (str[found - 1] == NULL)
				return (ft_free(str));
			found++;
		}
		else
			i++;
	}
	str[found - 1] = NULL;
	return (str);
}

char	**ft_free(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
