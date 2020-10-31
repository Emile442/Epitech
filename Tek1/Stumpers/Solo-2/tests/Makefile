##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## tests
##

NAME	=	unit-tests

SRC		=	../src/anagram.c	\
			test_anagram.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-I ../include

LDFLAGS	=	-L./../lib/my --coverage -lmy -lcriterion

all: $(NAME)
	
$(NAME): $(OBJ)
	make -C ../lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)
	

tests_run: all
	./$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
