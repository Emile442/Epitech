#
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Zappy AI
##

NAME 	= 	zappy_ai

SRC		=	src/main.c 							\
			src/core/create.c					\
			src/core/destroy.c					\
			src/core/loop.c						\
			src/core/dispatch_recv.c			\
			src/network/create.c				\
			src/network/destroy.c				\
			src/network/bind.c					\
			src/network/loop.c					\
			src/network/recv.c					\
			src/network/send.c					\
			src/network/setup.c					\
			src/utils/format_str.c				\
			src/utils/parse_str.c				\
			src/utils/arraylen.c				\
			src/utils/str_is_int.c				\
			src/utils/check_alphanum.c			\
			src/commands/cmd_register.c			\
			src/commands/cmd_death.c			\
			src/option.c						\


OBJ 	=	$(SRC:.c=.o)

CC		= 	gcc

CFLAGS	=	-W -Wall -Wno-deprecated -I ./includes

all: $(NAME)

$(NAME): $(OBJ)
	gcc -w -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
