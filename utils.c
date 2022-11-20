#include "push_swap.h"

int	ft_atoi_base(char *str, int base)
{
	int	i;
	int	nb;
	int	sig;

	if (!str || !str[0])
		return (-1);
	i = 0;
	nb = 0;
	sig = 1;
	if (str[0] == '0' && str[1] == 'x')
		i = 2;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i])
	{
		ft_check(str, i, base);
		nb = nb * base;
		nb = nb + ft_return_nb(str, i, base);
		i++;
	}
	return (nb * sig);
}

static int	ft_return_nb(char *str, int i, int base)
{
	char	*hex1;
	char	*hex2;
	int		j;

	j = 0;
	hex1 = "0123456789abcdef";
	hex2 = "0123456789ABCDEF";
	while (j <= base)
	{
		if (str[i] == hex1[j] || str[i] == hex2[j])
			return (j);
		j++;
	}
	return (-1);
}
