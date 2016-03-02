#include "my.h"

void my_rm_all_eq_from_list(t_list **begin, void *data_ref, int (*cmp)())
{
	t_list *list;
	t_list *list0;
	t_list *list2;

	list = *begin;
	while (*begin)
	{
		if (cmp((list)->name, data_ref) == 0)
		{
			list2 = (*begin)->next;
			free(*begin);
			(*begin) = list2;
			list = list2;
		}
		else if (cmp((*begin)->name, data_ref) == 0)
		{
			list0->next = (*begin)->next;
			free(*begin);
			*begin = list0;
		}
		list0 = (*begin);
		(*begin) = (*begin)->next;
	}
	*begin = list;
}

char 		*set_rights(struct stat fileStat)
{
	char 	*rights;

	rights = "";
	rights = my_strcat(rights, (S_ISDIR(fileStat.st_mode)) ? "d" : ((S_ISLNK(fileStat.st_mode)) ? "l" : "_"));
	rights = my_strcat(rights, (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    rights = my_strcat(rights, (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    rights = my_strcat(rights, (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    rights = my_strcat(rights, (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    rights = my_strcat(rights, (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    rights = my_strcat(rights, (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    rights = my_strcat(rights, (fileStat.st_mode & S_IROTH) ? "r" : "-");
    rights = my_strcat(rights, (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    rights = my_strcat(rights, (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    return (rights);
}

char 		*set_time(time_t my_time)
{
	char 	*tmp;

	tmp = malloc(50);
	tmp = my_strcpy(ctime(&my_time));
	tmp[my_strlen(tmp) - 9] = '\0';
	tmp = tmp + 4;
	return (tmp);
}

t_list		*add_item(t_list *list, struct dirent *details, char* dirname)
{
	t_list	*node;
	struct 	stat fileStat;

	lstat(my_strcat(dirname, details->d_name), &fileStat);
	node = malloc(sizeof(*node));
	node->name = malloc(sizeof(char) * my_strlen(details->d_name));
	node->name = details->d_name;
	node->modif = set_time(fileStat.st_ctime);
	node->rights = set_rights(fileStat);
	node->size = fileStat.st_size;
	node->links = fileStat.st_nlink;
	node->usr =  getpwuid(fileStat.st_uid)->pw_name;
	node->grp = getgrgid(fileStat.st_gid)->gr_name;
	node->block = fileStat.st_blocks;
	node->next = list;

	return (node);
}

t_list		*add_item_file(t_list *list, char *d_name, char* dirname)
{
	t_list	*node;
	struct 	stat fileStat;

	lstat(dirname, &fileStat);
	node = malloc(sizeof(*node));
	node->name = malloc(sizeof(char) * my_strlen(d_name));
	node->name = d_name;
	node->modif = set_time(fileStat.st_ctime);
	node->rights = set_rights(fileStat);
	node->size = fileStat.st_size;
	node->links = fileStat.st_nlink;
	node->usr =  getpwuid(fileStat.st_uid)->pw_name;
	node->grp = getgrgid(fileStat.st_gid)->gr_name;
	node->block = fileStat.st_blocks;
	node->next = list;

	return (node);
}

t_list 		*make_list(char *dirname)
{
	DIR* 	rep;
	struct 	dirent* found;
	t_list	*list;

	list = NULL;
	rep = opendir(dirname);
	if (rep != 0)
	{
		while ((found = readdir(rep)) != NULL)
		{
			list = add_item(list, found, my_strcat(dirname, "/"));
		}
		return (list);
	}
	return (print_error(dirname));
}
