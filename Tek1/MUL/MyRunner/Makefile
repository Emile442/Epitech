##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## MyRunner
##

NAME	=	my_runner

SRC		=	main.c									\
			src/game_utils.c						\
			src/game_init.c							\
			src/game_anim.c							\
			src/game_update.c						\
			src/game_listener.c						\
			src/game_destroy.c						\
			src/clock_init.c						\
			src/player/player_init.c				\
			src/player/player_anim.c				\
			src/player/player_listener.c			\
			src/player/player_draw.c				\
			src/parallax/parallax_init.c			\
			src/parallax/parallax_anim.c			\
			src/parallax/parallax_draw.c			\
			src/box/box_colision.c					\
			src/box/box_waiting.c					\
			src/box/box_anim.c						\
			src/box/box_draw.c						\
			src/score/score_init.c					\
			src/score/score_draw.c					\
			src/score/score_update.c				\
			src/score/score_destroy.c				\
			src/map/map_init.c						\
			src/map/map_func.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-g -W -Wall -Wno-deprecated -I ./include

LDFLAGS	=	-L./lib/my -lmy

LCFLAGS = 	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc -w -o $(NAME) $(OBJ) $(LDFLAGS) $(LCFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
