

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

typedef struct	s_nb
{
	int	*n;
	int	i;
	int	len;
	int	start;
	int	numbers;
	char	*str;
}	t_nb;

void		ft_put_finish(char *c);

void		ft_check_numbers(int ac, char **av);

char		*ft_substr(char	*str, t_nb nb);
int		ft_atoi(char *str);
