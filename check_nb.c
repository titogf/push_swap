#include "push_swap.h"

static void	ft_check(int ac, char **av, t_nb nb);
static void	ft_repnb(t_nb nb);


void	ft_check_numbers(int ac, char **av)
{
	t_nb	nb;
	int	lenc;
	int	lenv;

	nb.numbers = 0;
	ft_check(ac, av, nb);
	nb.n = malloc (sizeof (int) * nb.numbers);
	nb.i = -1;
	lenc = 0;
	while (++lenc < ac)
	{
		lenv = -1;
		nb.start = -1;
		while (av[lenc][++lenv])
		{
			while (nb.start == -1 && av[lenc][lenv] == ' ')
				lenv++;
			if (nb.start == -1 && av[lenc][lenv] != ' ')
				nb.start = lenv;
			if (av[lenc][lenv] == ' ' || av[lenc][lenv + 1] == '\0')
			{
				nb.len = lenv - nb.start;
				if (nb.len == 0 || av[lenc][lenv + 1] == '\0')
					nb.len++;
				nb.str = ft_substr(av[lenv], nb);
				while (av[lenc][lenv + 1] == ' ')
					lenv++;
				nb.n[++nb.i] = ft_atoi(nb.str);
				printf("%d --- %d\n", nb.start, nb.len);
				nb.start = -1;
				printf("%s\n", nb.str);
			}
		}
	}
	ft_repnb(nb);
}

static void	ft_check(int ac, char **av, t_nb nb)
{
	int	i;
	int	j;

	if (ac < 2)
		exit (1);
	i = 0;
	nb.numbers = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{	if (av[i][j] == ' ' && av[i][j + 1] != ' ')
				nb.numbers++;
			if (av[i][j] < '0' || av[i][j] != ' ')
			{
				if (av[i][j] > '9')
					exit (1);
			}
		}
		nb.numbers++;
	}
}

static void	ft_repnb(t_nb nb)
{
	int	i;
	int	j;

	i = -1;
	while (nb.n[++i])
	{
		j = i;
		while (nb.n[++j])
		{
			if (nb.n[i] == nb.n[j])
				ft_put_finish("Error");
		}
	}
}
