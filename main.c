#include "push_swap.h"

//static void	ft_put_finish(char *c);

int	main(int ac, char **av)
{
	ft_check(ac, av);
	if (av[1][0] == '9')
		printf("9");
	sleep (4);
	return (0);
}

/*static void	ft_renumber(int ac, char **av)
{
	int	i;
	int	j;
	int	r;

	r = -1;
	while (++r)
	{
		i = 0;
		while (++i < ac)
		{
			r = av[i][j]
			j = -1;
			while (av[i][++j])
			{
				if (
			}
		}
	}
}*/

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
