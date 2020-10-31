##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for
##

NAME	=	lem_in

TEST_NAME	=	unit_tests

MAIN	=	src/main.c

SRC	=	src/error_handling/error_handling_utils.c	\
		src/parsing/anthill_utils.c			\
		src/parsing/count_words.c			\
		src/parsing/parsing_utils.c			\
		src/parsing/link_utils.c			\
		src/parsing/node_utils.c			\
		src/parsing/create_links.c			\
		src/parsing/create_nodes.c			\
		src/lemin.c					\

TEST_SRC=	tests/

OBJ	=	$(SRC:%.c=%.o) $(MAIN:%.c=%.o)

CFLAGS	=	-W -Wall -Wextra -Wshadow	\
		-Iinclude			\

LIB	=	my

LIB_PATH=	lib/my

LDFLAGS	=	-L$(LIB_PATH) -l$(LIB)

CC	=	gcc

RM	=	rm -f

TEST_FLAGS	=	--coverage	\
			-lcriterion	\

all	:
		make -C $(LIB_PATH)
		make $(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		make clean -C $(LIB_PATH)
		$(RM) $(OBJ) *.gc*

fclean	:	clean
		make fclean -C $(LIB_PATH)
		$(RM) $(NAME) $(TEST_NAME)

re	:	fclean all
		make re -C $(LIB_PATH)

tests_run	:
			make -C $(LIB_PATH)
			make $(TEST_NAME)
			./$(TEST_NAME)
			gcovr --exclude tests

$(TEST_NAME)	:
			$(CC) -o $(TEST_NAME) -Iinclude $(SRC) $(TEST_SRC) $(LDFLAGS) $(TEST_FLAGS)

.PHONY	:	clean fclean re
