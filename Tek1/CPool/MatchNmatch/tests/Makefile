##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Test match-nmatch
##

SRC	=	../match.c 		\
		../nmatch.c		\
		test_match.c	\
		test_nmatch.c

all:
	make -C ../lib/my/
	gcc -Wall $(SRC) --coverage -lcriterion -L ../lib/my -lmy -I../include/ -o unit_tests

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all