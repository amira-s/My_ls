##
## asciifun.c for octocat in /home/amira_s/octo/src
##
## Made by AMIRA Syrine
## Login   <amira_s@etna-alternance.net>
##
## Started on  Fri Jan  22 12:23:25 2015 AMIRA Syrine
## Last update Fri Jan  22 16:45:07 2015 AMIRA Syrine
##

NAME		=	my_ls

SRC 		=	lib/my_putchar.c 		\
				lib/my_putstr.c 		\
				lib/my_put_nbr.c 		\
				lib/my_getnbr.c 		\
				lib/my_strlen.c 		\
				lib/my_strcmp.c 		\
				lib/my_strcpy.c 		\
				lib/my_strcat.c 		\
				lib/trace.c   	        \
				lib/swap.c   	        \
				lib/memcpy.c   	        \
				src/listing.c 	        \
				src/node.c 				\
				src/show.c 				\
				src/timesort.c 			\
				src/sort.c 				\
				src/checkfiletype.c 	\
				src/main.c

INC_DIR		=	.

OBJ			=	$(SRC:%.c=%.o)

CFLAGS		=   -g -W -Wall -pedantic -ansi -Wextra

CC			=	gcc

RM			=	rm -f

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
