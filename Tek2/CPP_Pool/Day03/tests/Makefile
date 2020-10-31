##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Test Makefile for Navy
##

NAME	=	unit_tests

TEST_DIR = tests

SRC		= 	string.c							\
			assign.c							\
			append.c							\
			at.c								\
			clear.c								\
			size.c								\
			compare.c							\
			copy.c								\
			c_str.c								\
			empty.c								\
			find.c								\
			insert.c							\
			to_int.c							\
			$(TEST_DIR)/test_string.c			\
			$(TEST_DIR)/test_assign.c			\
			$(TEST_DIR)/test_append.c			\
			$(TEST_DIR)/test_at.c				\
			$(TEST_DIR)/test_clear.c			\
			$(TEST_DIR)/test_size.c				\
			$(TEST_DIR)/test_compare.c			\
			$(TEST_DIR)/test_compare2.c			\
			$(TEST_DIR)/test_copy.c				\
			$(TEST_DIR)/test_c_str.c			\
			$(TEST_DIR)/test_empty.c			\
			$(TEST_DIR)/test_find_s.c			\
			$(TEST_DIR)/test_find_c.c			\
			$(TEST_DIR)/test_insert.c			\
			$(TEST_DIR)/test_to_int.c			\

CC	=	gcc

RM	=	rm -f

LDFLAGS	=	-lcriterion
CFLAGS	=	-W -Wall -iquote ../ --coverage

INCLUDE	=	-I../

all	:	$(NAME)

$(NAME)	:
	cd .. && $(CC) $(INCLUDE) -o $(NAME) $(SRC) $(LDFLAGS) $(CFLAGS)
	../$(NAME)
	cd .. && gcovr --exclude tests

clean:
	$(RM) *.o
	$(RM) ../*.o
	$(RM) ../*.gc*
	$(RM) ./*.gc*

clean_cov:
	$(RM) ../*.gc*
	$(RM) ./*.gc*

fclean	:	clean
	$(RM) ../unit_tests

re: fclean all

.PHONY: clean fclean re
