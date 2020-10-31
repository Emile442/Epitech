##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## MyDefender
##

NAME	=	my_defender

SRC		=	main.c										\
			src/core/init.c								\
			src/core/update.c							\
			src/core/destroy.c							\
			src/core/cursor/init.c						\
			src/core/cursor/draw.c						\
			src/core/cursor/destroy.c					\
			src/core/cursor/default.c					\
			src/utils/usage.c							\
			src/utils/spt.c								\
			src/utils/button.c							\
			src/utils/intersect.c							\
			src/utils/int_to_str.c						\
			src/utils/music.c							\
			src/utils/str_with_num.c					\
			src/scenes/init.c							\
			src/scenes/destroy.c						\
			src/scenes/home/init.c						\
			src/scenes/home/draw.c						\
			src/scenes/home/destroy.c					\
			src/scenes/home/button/play.c				\
			src/scenes/home/button/quit.c				\
			src/scenes/game/init.c						\
			src/scenes/game/draw.c						\
			src/scenes/game/destroy.c					\
			src/scenes/game/enemy/init.c				\
			src/scenes/game/enemy/draw.c				\
			src/scenes/game/enemy/add.c					\
			src/scenes/game/enemy/destroy.c				\
			src/scenes/game/enemy/utils.c				\
			src/scenes/game/hud/init.c					\
			src/scenes/game/hud/draw.c					\
			src/scenes/game/hud/destroy.c				\
			src/scenes/game/hud/button_tower_1.c		\
			src/scenes/game/hud/button_tower_2.c		\
			src/scenes/game/hud/button_tower_3.c		\
			src/scenes/game/hud/button_tower_available.c\
			src/scenes/game/hud/button_plane.c			\
			src/scenes/game/hud/button_pause.c			\
			src/scenes/game/hud/scoreboard/init.c		\
			src/scenes/game/hud/scoreboard/draw.c		\
			src/scenes/game/hud/scoreboard/destroy.c	\
			src/scenes/game/enemy/move_left.c			\
			src/scenes/game/enemy/move_up_down.c		\
			src/scenes/game/weapons/init.c				\
			src/scenes/game/weapons/draw.c				\
			src/scenes/game/weapons/add.c				\
			src/scenes/game/weapons/utils.c				\
			src/scenes/game/weapons/destroy.c			\
			src/scenes/game/weapons/delta_charlie.c		\
			src/scenes/game/keyboard_event.c			\
			src/scenes/pause/init.c						\
			src/scenes/pause/destroy.c					\
			src/scenes/pause/draw.c						\
			src/scenes/pause/button/quit.c				\
			src/scenes/pause/button/resume.c			\
			src/scenes/pause/button/home.c				\

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wno-deprecated -I ./include

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
	make -C lib/my re

.PHONY: all clean fclean re
