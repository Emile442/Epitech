##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Infinit Compile
##

SRC		=	test_infinit_add.c	\
			../infinit_add.c	\
			../convert.c	\
			../infinit_f.c	\
			../addition.c	\
			../soustraction.c

NAME	=	tests_run

all:
	make -C ../lib/my/
	gcc $(SRC) --coverage -lcriterion -L../lib/my -lmy -I../include/ -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all