##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## PUSH_SWAP
##

NAME	=	push_swap

SRC		=	main.c				\
			src/list_func.c		\
			src/pushswap_func.c \
			src/check_args.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -I ./include

LDFLAGS	=	-L./lib/my -lmy -g

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