##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##


NAME = my_convert_temp

SRC = 	my_convert_temp.c 				\

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
