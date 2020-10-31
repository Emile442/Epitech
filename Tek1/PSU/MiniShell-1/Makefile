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
			src/core/exec.c				\
			src/core/parsing.c			\
			src/core/dispatch.c			\
			src/env/init_env.c			\
			src/env/get_env.c			\
			src/env/get_env_path.c		\
			src/utils/filehandle.c		\
			src/utils/validation.c		\
			src/builtins/exit_cmd.c		\
			src/builtins/env_cmd.c		\
			src/builtins/cd_cmd.c		\
			src/builtins/setenv_cmd.c	\
			src/builtins/unsetenv_cmd.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -I ./include

LDFLAGS	=	-L./lib/my -lmy

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

library_re:
	$(MAKE) -C lib/my re

re:	library_re fclean all

.PHONY: all clean fclean re
