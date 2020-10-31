##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Rush2 Compile
##

SRC		=	my_params_to_list.c \
			my_list_size.c		\
			my_rev_list.c		\
			my_apply_on_nodes	\
			main.c

NAME	=	a.out

all:
	make -C ./lib/my/
	gcc $(SRC) -L./lib/my -lmy -I./include/ -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all