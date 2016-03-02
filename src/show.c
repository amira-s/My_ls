#include "my.h"

void show_total(t_list *list)
{
	int total;

	total = 0;
	while (list)
	{
		total += (list->block / 2);
		list = list->next;
	}
	my_putstr("total ");
	my_put_nbr(total);
	my_putstr("\n");
}

void show_list_detailed(t_list *list)
{
	show_total(list);
	while (list != NULL)
	{
		my_putstr(list->rights);
		my_putstr("  ");
		my_put_nbr(list->links);
		my_putstr("  ");
		my_putstr(list->usr);
		my_putstr("  ");
		my_putstr(list->grp);
		my_putstr("	 ");
		my_put_nbr(list->size);
		my_putstr("	 ");
		my_putstr(list->modif);
		my_putstr("  ");
		my_putstr(list->name);
		my_putstr("\n");
		list = list->next;
	}
}

void show_list_basic(t_list *list)
{
	while (list != NULL)
	{
		my_putstr(list->name);
		my_putstr(" 	");
		list = list->next;
	}
	my_putstr("\n");
}

void *print_error(char *dirname)
{
	my_putstr("my_ls: ");
	my_putstr(dirname);
	my_putstr(": No such file or directory\n");
	return (NULL);
}
