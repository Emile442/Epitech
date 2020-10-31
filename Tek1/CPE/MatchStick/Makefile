##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## matchstick
##

NAME	=	matchstick

SRC		=	main.c				\
			src/matchstick.c	\
			src/map/generator.c	\
			src/map/print.c		\
			src/map/remove.c	\
			src/map/utils.c		\
			src/turn/player.c	\
			src/turn/ia.c		\
			src/turn/ia_utils.c		\
			src/game.c

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

library_re:
	$(MAKE) -C lib/my re

re:	library_re fclean all

.PHONY: all clean fclean re
