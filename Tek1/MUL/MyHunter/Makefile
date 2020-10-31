##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## MyHunter
##

NAME	=	my_hunter

SRC		=	main.c					\
			src/graphics_utils.c	\
			src/maths_utils.c		\
			src/game_event.c		\
			src/game_render.c		\
			src/game_scoreboard.c	\
			src/bird_hunter.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-I ./include

LDFLAGS	=	-L./lib/my -lmy

LCFLAGS = 	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)
	
$(NAME): $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(LCFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re