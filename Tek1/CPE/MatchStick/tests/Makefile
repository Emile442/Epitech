##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## tests
##

NAME	=	unit-tests

SRC		=	../src/matchstick.c				\
			../src/map/generator.c			\
			../src/map/print.c				\
			../src/map/remove.c				\
			../src/map/utils.c				\
			../src/turn/player.c			\
			../src/turn/ia.c				\
			../src/turn/ia_utils.c			\
			../src/game.c					\
			test_map_generator.c			\
			test_map_remove.c				\
			test_map_utils.c				\
			test_game_status.c				\
			test_turn_ia_utils.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-I ../include --coverage

LDFLAGS	=	-L./../lib/my --coverage -lmy -lcriterion

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

tests_run: all
	./$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) -R *.gcno *.gcda ../src/*.gcno ../src/*.gcda
	$(RM) -R ../src/map/*.gcno ../src/map/*.gcda
	$(RM) -R ../src/turn/*.gcno ../src/turn/*.gcda

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
