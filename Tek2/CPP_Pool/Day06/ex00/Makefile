##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##


NAME = my_cat

SRC = 	my_cat.c 				\

CFLAGS = -std=gnu11 -W -Wall -Wextra

OBJ = $(SRC:%.c=%.o)
CC = g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
