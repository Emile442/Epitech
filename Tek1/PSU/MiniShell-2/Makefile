##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## minishell1
##

NAME	=	mysh

SRC		=	main.c 						\
			src/core/init.c				\
			src/core/prompt.c			\
			src/core/pre_exec.c			\
			src/core/exec.c				\
			src/core/parsing.c			\
			src/core/dispatch.c			\
			src/core/error.c			\
			src/env/init_env.c			\
			src/env/get_env.c			\
			src/env/get_env_path.c		\
			src/utils/filehandle.c		\
			src/utils/free_double_char.c\
			src/utils/validation.c		\
			src/utils/parse_str.c		\
			src/builtins/exit_cmd.c		\
			src/builtins/env_cmd.c		\
			src/builtins/cd_cmd.c		\
			src/builtins/setenv_cmd.c	\
			src/builtins/unsetenv_cmd.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -I ./include

LDFLAGS	=	-L./lib/my -lmy

all: compile_lib $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

compile_lib:
	make -C lib/my

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

library_re:
	$(MAKE) -C lib/my re

re:	library_re fclean all

.PHONY: all clean fclean re
