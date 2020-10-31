##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## tests
##

NAME	=	unit-tests

SRC		=	../src/sokoban.c			\
			../src/fs_file.c			\
			../src/maps_info.c			\
			../src/maps.c				\
			../src/player.c				\
			../src/player_move.c		\
			../src/print_move.c			\
			../src/map_checker.c		\
			../src/game_status.c		\
			test_map.c					\
			test_move_player.c			\
			test_move_box.c				\
			test_move_wall.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-I ../include --coverage

LDFLAGS	=	-L./../lib/my -lmy -lcriterion -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

tests_run: all
	./$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) *.gcno *.gcda
	$(RM) ../src/*.gcno

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re