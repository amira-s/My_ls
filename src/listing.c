#include "my.h"

void ls_basic(char *dirname, int i, int r, int a)
{
	t_list *list;

	if (i == 2)
		list = make_sorted_list(dirname);
	else if (i == 0)
	{
		list = 	make_list(dirname);
		my_sort_list(&list, cmp_casse);		
	}
	if (r == 1)
		my_rev_list(&list);
	if (a == 0)
		ls_a(&list);
	else if (a == 2)
	{
		my_rm_all_eq_from_list(&list, ".", my_strcmp);
		my_rm_all_eq_from_list(&list, "..", my_strcmp);
	}
	if (list)
		show_list_basic(list);
}

void ls_l(char *dirname, int i, int r, int a)
{
	t_list *list;

	if (i == 2)
		list = make_sorted_list(dirname);
	else if (i == 0)
	{
		list = 	make_list(dirname);
		my_sort_list(&list, cmp_casse);		
	}
	if (r == 1)
		my_rev_list(&list);
	if (a == 0)
		ls_a(&list);
	else if (a == 2)
	{
		my_rm_all_eq_from_list(&list, ".", my_strcmp);
		my_rm_all_eq_from_list(&list, "..", my_strcmp);
	}
	if (list)
		show_list_detailed(list);
}

void ls_a(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	while (*list)
	{
		if ((*list)->name[0] == '.')
			my_rm_all_eq_from_list(&tmp, (*list)->name, my_strcmp);
		*list = (*list)->next;
	}
	*list = tmp;
}


void ls_R(char *dirname, int i, int r, int a)
{
	DIR* rep;
	struct dirent* found;

	rep = opendir(dirname);
	while ((found = readdir(rep)) != NULL){
		if (my_strcmp(found->d_name, ".") != 0 && 
			my_strcmp(found->d_name, "..") != 0)
		{
			my_putstr(found->d_name);
			my_putstr("\n");
		}
	}
}

