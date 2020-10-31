##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Infinit
##

SRC		=	main.c \
			infinit_add.c	\
			convert.c	\
			infinit_f.c	\
			addition.c	\
			soustraction.c

NAME	=	infin_add

all:
	make -C ./lib/my/
	gcc $(SRC) -L./lib/my -lmy -I./include/ -Werror -Wextra -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all