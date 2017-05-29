#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *zero = lst;
	int issorted = 0;
	int temp;
	while (!issorted)
	{
		issorted = 1;
		while (lst->next)
		{
			if (!cmp(lst->data, lst->next->data))
			{
				issorted = 0;
				temp = lst->next->data;
				lst->next->data = lst->data;
				lst->data = temp;
			}
			lst = lst->next;
		}
		lst = zero;
	}
	return (lst);
}
