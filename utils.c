#include "push_swap.h"

void	ft_check(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 2)
		exit (1);
	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] < '0' || av[i][j] != ' ')
			{
				if (av[i][j] > '9')
					exit (1);
			}
		}
	}
}

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
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sig);
}
