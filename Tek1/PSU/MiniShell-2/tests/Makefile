##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## tests
##

NAME	=	unit-tests

SRC		= 	test_env.c						\
			../src/core/init.c				\
			../src/core/prompt.c			\
			../src/core/exec.c				\
			../src/core/pre_exec.c			\
			../src/core/parsing.c			\
			../src/core/error.c				\
			../src/core/dispatch.c			\
			../src/env/init_env.c			\
			../src/env/get_env.c			\
			../src/env/get_env_path.c		\
			../src/utils/filehandle.c		\
			../src/utils/validation.c		\
			../src/utils/free_double_char.c	\
			../src/utils/parse_str.c		\
			../src/builtins/exit_cmd.c		\
			../src/builtins/env_cmd.c		\
			../src/builtins/cd_cmd.c		\
			../src/builtins/setenv_cmd.c	\
			../src/builtins/unsetenv_cmd.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -I ../include -lcriterion

LDFLAGS	=	-L./../lib/my -lmy

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
