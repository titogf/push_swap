#include "push_swap.h"

int	main(int ac, char **av)
{
	ft_check_numbers(ac, av);
	sleep (4);
	return (0);
}

void	ft_put_finish(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		write(1, &c[i], 1);
		i++;
	}
	exit (1);
}
