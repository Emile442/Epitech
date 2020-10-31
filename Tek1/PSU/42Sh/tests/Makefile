##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## tests
##

NAME	=	unit-tests

SRC		= 	test_env.c						\

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -I ../include -lcriterion

LDFLAGS	=	-L./../lib/my -lmy

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

tests_run: all
	./$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) *.gcno *.gcda
	$(RM) ../src/*.gcno

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
