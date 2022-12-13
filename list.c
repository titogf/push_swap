
#include "push_swap.h"

t_list	ft_create_list(t_nb *nb)
{
	t_list	*list;
	int	i;

	i = -1;
	list = malloc (sizeof (t_list));
	list->content = 0;
	while (++i < nb->numbers)
	{
		list->content = nb->n[i];
		list = list->next;
	}
	list->content = '\0';
	return (*list);
}
