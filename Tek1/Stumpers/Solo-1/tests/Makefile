##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## tests
##

NAME	=	unit-tests

SRC		=	../src/list_func.c		\
			../src/check_args.c		\
			../src/pushswap_func.c	\
			test_list_push.c		\
			test_list_count.c		\
			test_list_reverse.c		\
			test_list_pull.c		\
			test_list_smaller.c		\
			test_list_check.c		\
			test_ps_ra.c			\
			test_ps_pb.c			\
			test_ps_pa.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -I ../include --coverage

LDFLAGS	=	-L./../lib/my -lmy -lcriterion

all: $(NAME)
	
$(NAME): $(OBJ)
	make -C ../lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CFLAGS)

tests_run: all
	./$(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) *.gcno *.gcda
	$(RM) ../src/*.gcno ../src/*.gcda

re:	fclean all

.PHONY: all clean fclean re