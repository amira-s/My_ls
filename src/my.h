#ifndef __MY__
# define __MY__

#define _BSD_SOURCE

#include <stdlib.h>
#include <getopt.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <dirent.h>
#include <limits.h>

#include "../lib/colors.h"
#include "my_struct.h"
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <stdio.h> /* DEBUG */

/*/lib*/
void		my_putchar(char c);
int			my_getnbr();
void		my_put_nbr();
void		my_putstr(char *);
int			my_strlen(char *);
int			my_strcmp(char *, char *);
char		*my_strcat(char *, char *);
char		*my_strcpy(char *src);
char		*my_strdup(char *);
void        *trace(void*, char* msg);
int 		my_isint(char *str);
void 		my_swap(void* a, void* b, int size);
void 		int_swap(int *a, int *b);
/*listing*/
void 		ls_basic(char *dirname, int i, int r, int a);
void 		ls_l(char *dirname, int i, int r, int a);
void 		ls_a(t_list **list);
void 		ls_R(char *dirname, int i, int r, int a);

/*node.c*/
char 		*set_rights(struct stat fileStat);
t_list		*add_item(t_list *list, struct dirent *details, char* dirname);
t_list 		*make_list(char *dirname);
void 		my_rm_all_eq_from_list(t_list **begin, void *data_ref, int (*cmp)());
t_list		*add_item_file(t_list *list, char *d_name, char* dirname);


/*sort*/
void		my_rev_list(t_list **begin);
void		my_sort_list(t_list **begin, int (*cmp)());
int 		cmp_casse(char *p1, char *p2);

/*show*/
void 		show_list_basic(t_list *list);
void 		show_list_detailed(t_list *list);
void 		*print_error(char *dirname);

/*timesort*/
void		my_put_elem_in_sort_list(t_list **begin, struct dirent *details, char *dirname);
t_list    	*make_sorted_list(char *dirname);
int 		cmp_time(char *name1, char *name2);

/*filetype*/
int is_file(const char *path);
int is_dir(const char *path);



#endif /* __MY__ */
