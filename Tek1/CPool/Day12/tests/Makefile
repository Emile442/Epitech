##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Cat Compile
##

SRC		=	test_cat.c ../cat/cat.c

NAME	=	tests_run

all:
	make -C ../lib/my/
	gcc $(SRC) -L../lib/my -lmy -I../include/ -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all