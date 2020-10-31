##
## EPITECH PROJECT, 2019
## Makefile of libmy.a
## File description:
## Create my library
##

AR		= ar rc

CC		= gcc

RM		= rm -rf

NAME	= libstring.a

SRC		=	string.c	\
			assign.c	\
			append.c	\
			at.c		\
			clear.c		\
			size.c		\
			compare.c	\
			copy.c		\
			c_str.c		\
			empty.c		\
			find.c		\
			insert.c	\
			to_int.c	\

OBJ		= $(SRC:.c=.o)

CFLAGS	= -iquote ./ -W -Wall -Wextra -Wshadow

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

new:
	touch $(file).c
	touch tests/test_$(file).c

tests_run:
	make -C tests

.PHONY: clean fclean re
