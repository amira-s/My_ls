/*
** asciifun.c for octocat in /home/amira_s/octo/src
**
** Made by AMIRA Syrine
** Login   <amira_s@etna-alternance.net>
**
** Started on  Fri Jan  22 16:23:25 2015 AMIRA Syrine
** Last update Fri Jan  22 16:45:07 2015 AMIRA Syrine
*/

#ifndef __MY_STRUCT__
# define __MY_STRUCT__

typedef struct       s_list
{
    char *name;
    char *usr;
    char *grp;
    char *rights;
    int  size;
    char *modif;
    int  links;
    int  block;  
    struct s_list    *next;
}                    t_list;


#endif
