##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##


NAME = menger

SRC = 	main.c 				\
		menger.c

CFLAGS = -std=gnu11 -W -Wall -Wextra -I ./include

OBJ = $(SRC:%.c=%.o)
CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
