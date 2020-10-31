##
## EPITECH PROJECT, 2020
## Makefile - Boiler Template
## File description:
## Run Tests
##

NAME	=	unit-tests

SRC		=	example_tests.cpp

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-I ../include --coverage

LDFLAGS	=	-lcriterion --coverage

CC		=	g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) *.o
	$(RM) *.gc*

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
