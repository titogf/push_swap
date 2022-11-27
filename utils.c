
#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sig;

	if (!str || !str[0])
		return (-1);
	i = 0;
	nb = 0;
	sig = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i])
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sig);
}

char	*ft_substr(char	*str, t_nb nb)
{
	int	i;
	int	len;
	int	start;
	char	*c;

	start = nb.start;
	len = nb.len;
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
