##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## MY_LS
##

NAME	=	my_ls

SRC		=	main.c				\
			src/my_ls.c			\
			src/parse_params.c	\
			src/list_func.c		\
			src/acl.c			\
			src/utils.c			\
			src/display.c		\
			src/order.c			\
			src/error.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -I ./include

LDFLAGS	=	-L./lib/my -lmy

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
