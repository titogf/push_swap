#include "push_swap.h"

static void	ft_check(int ac, char **av);
//static void	ft_put_finish(char *c);

int	main(int ac, char **av)
{
	ft_check(ac, av);
	if (av[1][0] == '9')
		printf("9");
	sleep (4);
	return (0);
}

static void	ft_check(int ac, char **av)
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

/*static void	ft_put_finish(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	exit (1);
}*/
