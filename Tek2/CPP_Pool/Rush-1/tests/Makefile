##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Test Makefile
##

NAME	=	unit_tests

TEST_DIR = tests

SRC		= 	new.c										\
			vertex.c									\
			point.c										\
			int.c										\
			float.c										\
			char.c										\
			$(TEST_DIR)/vertex/test_vertex.c			\
			$(TEST_DIR)/vertex/test_vertex_operator.c	\
			$(TEST_DIR)/point/test_point.c				\
			$(TEST_DIR)/point/test_point_operator.c		\
			$(TEST_DIR)/int/test_int.c					\
			$(TEST_DIR)/int/test_int_operator.c			\
			$(TEST_DIR)/int/test_int_comparator.c		\
			$(TEST_DIR)/float/test_float.c				\
			$(TEST_DIR)/float/test_float_comparator.c	\
			$(TEST_DIR)/float/test_float_operator.c		\
			$(TEST_DIR)/char/test_char.c				\
			$(TEST_DIR)/char/test_char_comparator.c		\
			$(TEST_DIR)/char/test_char_operator.c		\


CC	=	gcc

RM	=	rm -f

LDFLAGS	=	-lcriterion
CFLAGS	=	-W -Wall -I ../ --coverage

INCLUDE	=	-I../

all	:	$(NAME)

$(NAME)	:
	cp *.h ../
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
