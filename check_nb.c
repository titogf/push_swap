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

void	ft_renumber(int ac, char **av)
{
	t_nb	nb;
	int	lenc;
	int	lenv;

	nb.i = -1;
	lenc = 0;
	while (++lenc < ac)
	{
		lenv = -1;
		nb.start = 0;
		while (av[lenc][++lenv])
		{
			while (nb.start == 0 && av[lenc][lenv] == ' ')
				lenv++;
			if (av[lenc][lenv] != ' ')
				nb.start = lenv;
			if (av[lenc][lenv] == ' ' || av[lenc][lenv + 1] == '\0')
			{
				nb.len = lenv;
				nb.str = ft_substr(av[lenv], nb);
				while (av[lenc][lenv + 1] == ' ')
					lenv++;
				nb.n[++nb.i] = ft_atoi(nb.str);
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
