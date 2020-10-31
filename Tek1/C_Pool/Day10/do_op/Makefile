##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Build OBJ
##

SRC		=	do_op.c \
			operations.c

NAME	=	do-op

all:
	make -C ../lib/my/
	gcc $(SRC) -L../lib/my -lmy -I../include/ -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all