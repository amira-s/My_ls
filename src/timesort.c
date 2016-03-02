#include "my.h"

void		my_put_elem_in_sort_list(t_list **begin, struct dirent *details, char * dirname)
{
    t_list	*tmp;
    t_list	*toadd;

    tmp = *begin;
    if (cmp_time(details->d_name, (*begin)->name) > 0)
    {
        *begin = add_item((*begin), details, dirname);
        tmp = *begin;
    }
    else
    {
        while ((*begin)->next)
        {
            if (cmp_time(my_strcat(dirname, details->d_name), my_strcat(dirname, ((*begin)->next)->name)) > 0)
            {
                toadd = add_item((*begin)->next, details, dirname);
                (*begin)->next = toadd;
                *begin = tmp;
                return ;
            }
            (*begin) = (*begin)->next;
        }
        (*begin)->next = add_item((*begin)->next, details, dirname);
    }
    *begin = tmp;
}

char *trunc_str(char *str)
{
    int i;
    int j;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '/')
            j = i;
    }
    return (str + j + 1);
}

t_list    *make_sorted_list(char *dirname)
{
    DIR*  rep;
    struct  dirent* found;
    t_list  *list;
    int i;

    list = NULL;
    rep = opendir(dirname);
    if (rep != 0)
    {
        for (i = 0; (found = readdir(rep)) != NULL; i++)
        {
            if (i == 0)
                list = add_item(list, found, my_strcat(dirname, "/"));
            else
                my_put_elem_in_sort_list(&list, found, my_strcat(dirname, "/"));
        }
        return (list);
    }
    else if (is_file(dirname))
    {
        list = add_item_file(list, trunc_str(dirname), dirname);
        return (list);
    }
    return (print_error(dirname));
}

int cmp_time(char *name1, char *name2)
{
    struct  stat fileStat;
    struct  stat currentStat;

    lstat(name1, &fileStat);
    lstat(name2, &currentStat);
    if (fileStat.st_ctime > currentStat.st_ctime)
        return (1);
    else
        return (0);
}
