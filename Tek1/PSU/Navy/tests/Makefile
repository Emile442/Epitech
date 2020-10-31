##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Test Makefile for Navy
##

NAME	=	unit_tests

SRC_DIR	=	src

SRC	=	$(SRC_DIR)/map/check_file_errors.c	\
		$(SRC_DIR)/map/get_map.c		\
		$(SRC_DIR)/map/load_file_in_mem.c	\
		$(SRC_DIR)/map/verify_local_attack.c	\
		$(SRC_DIR)/map/gameover.c	\
		$(SRC_DIR)/map/utils.c	\
		$(SRC_DIR)/signal/stock_bits.c		\
		tests/test_check_file_errors.c	\
		tests/test_get_map.c		\
		tests/test_load_file_in_mem.c	\
		tests/test_stock_bits.c		\
		tests/test_map_verify_local_attack.c		\
		tests/test_map_gameover.c		\
		tests/test_map_utils.c		\

LIB_DIR	=	lib/my

LIB	=	my

CC	=	gcc

RM	=	rm -f

LDFLAGS	=	-lcriterion		\
		-L$(LIB_DIR) -l$(LIB)	\
		--coverage		\

INCLUDE	=	-Iinclude

all	:	$(NAME)

$(NAME)	:
		cd .. && $(CC) $(INCLUDE) -o $(NAME) $(SRC) $(LDFLAGS)
		../$(NAME)
		cd .. && gcovr --exclude tests

clean	:
		$(RM) ../*.gc*

fclean	:	clean
		$(RM) ../unit_tests

re	:	fclean all

.PHONY	:	clean fclean re
