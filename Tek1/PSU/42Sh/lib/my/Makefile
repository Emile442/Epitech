##
## EPITECH PROJECT, 2018
## Makefile of libmy.a
## File description:
## Create my library
##

AR	:= ar rc

CC	:= gcc

RM	:= rm -rf

NAME	:= libmy.a

SRC	:=	my_put_basic.c		\
		my_len.c		\
		my_get_nbr.c 		\
		my_str_isnum.c		\
		my_printf.c		\
		my_print_alpha.c	\
		my_print_nbr.c		\
		my_str_to_word_array.c	\
		my_strcmp.c		\
		get_next_line.c		\
		my_put_error.c		\
		my_str_isalpha.c	\

OBJ	:= $(SRC:.c=.o)

CFLAGS	:= -I../../include \
	   -W -Wall -Wextra -Wshadow \

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
