##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## STUMPER
##

NAME	=	sort_words

SRC		=	main.c

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
