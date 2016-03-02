#include "my.h"

void		my_rev_list(t_list **begin)
{
	t_list	*tmp;
	t_list	*rlist;

	rlist = 0;
	while (*begin)
	{
		tmp = *begin;
		*begin = (*begin)->next;
		tmp->next = rlist;
		rlist = tmp;
	}
	*begin = rlist;
}

void		my_sort_list(t_list **begin, int (*cmp)())
{
	t_list	*tmp;
	int		test;

	test = 0;
	tmp = *begin;
	while (test == 0 && *begin)
	{
		*begin = tmp;
		test = 1;
		while ((*begin)->next)
		{
			if (cmp((*begin)->name, ((*begin)->next)->name) > 0)
			{
				my_swap(&(*begin)->name, &((*begin)->next)->name, sizeof((*begin)->name));
				my_swap(&(*begin)->usr, &((*begin)->next)->usr, sizeof((*begin)->usr));
				my_swap(&(*begin)->modif, &((*begin)->next)->modif, sizeof((*begin)->modif));
				my_swap(&(*begin)->grp, &((*begin)->next)->grp, sizeof((*begin)->grp));
				my_swap(&(*begin)->rights, &((*begin)->next)->rights, sizeof((*begin)->rights));
				int_swap(&(*begin)->size, &((*begin)->next)->size);
				int_swap(&(*begin)->block, &((*begin)->next)->block);
				int_swap(&(*begin)->links, &((*begin)->next)->links);
				test = 0;
			}
			(*begin) = (*begin)->next;
		}

	}
	*begin = tmp;
}

int cmp_casse(char *p1, char *p2)
{
	while (*p1 != '\0') {
		if (*p2 == '\0') 
			return  1;
		if (*p2 > *p1)   
			return -1;
		if (*p1 > *p2)   
			return  1;
		p1++;
		p2++;
	}
	if (*p2 != '\0') 
		return -1;
	return 0;
}
