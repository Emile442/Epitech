##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## SOKOBAN
##

NAME	=	my_sokoban

SRC		=	main.c					\
			src/sokoban.c			\
			src/fs_file.c			\
			src/maps_info.c			\
			src/maps.c				\
			src/player.c			\
			src/player_move.c		\
			src/print_move.c		\
			src/map_checker.c		\
			src/game_status.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-I ./include

LDFLAGS	=	-L./lib/my -lmy

LIB		= -lncurses

all: $(NAME)
	
$(NAME): $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(LIB)

tests_run:
	make -C tests tests_run

clean:
	$(RM) $(OBJ)
	$(RM) src/*.gcno

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re