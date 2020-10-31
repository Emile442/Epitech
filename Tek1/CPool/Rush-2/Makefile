##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Rush2 Compile
##

SRC		=	rush2.c count_alpha.c

NAME	=	rush2

all:
	make -C ./lib/my/
	gcc $(SRC) -L./lib/my -lmy -I./include/ -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all