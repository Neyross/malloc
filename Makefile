##
## EPITECH PROJECT, 2020
## CPE_dante_2019
## File description:
## Makefile
##

SRC     =	$(wildcard *.c)

NAME    =	libmy_malloc.so

CFLAGS  =		-fno-builtin \
				-W      \
				-Wall	\
				-Wextra	\

SHAREDFLAGS =	-shared	\
				-fPIC	\
				-ldl	\
				-Wall

all:    $(NAME)

$(NAME):
		gcc $(SHAREDFLAGS) -o $(NAME) $(SRC)

clean:
		rm -f vgcore.*
		rm -f *~
		rm -f \#*#
		rm -f *.gc*
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re:     fclean all

