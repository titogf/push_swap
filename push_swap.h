

#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

typedef struct	s_nb
{
	int	*n;
	int	i;
	int	len;
	int	start;
	char	*str;
}	t_nb;

void		ft_check(int ac, char **av);
void		ft_renumber(int ac, char **av);
char		*ft_substr(char	*str, t_nb nb);
int		ft_atoi(char *str);
