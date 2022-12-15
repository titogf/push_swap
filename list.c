
#include "push_swap.h"

t_list	ft_create_list(t_nb *nb)
{
	t_list	*list;
	int	i;

	list = malloc (sizeof (t_list));
	list->next = malloc (sizeof (t_list));
	i = -1;
	while (++i < nb->numbers)
	{
		list->content = nb->n[i];
		list = list->next;
	}
	list->content = '\0';
	return (*list);
}
