##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile of project
##

CC		:= gcc

RM		:= rm -f

NAME	:= 42sh

SRC		:= 	src/main.c							\
			src/utils/shortcut.c				\
			src/utils/chained_list.c			\
			src/utils/utils_list.c				\
			src/core/dispatch.c					\
			src/core/exec.c						\
			src/core/prompt.c					\
			src/core/check_error.c				\
			src/core/utils.c			\
			src/core/line_formating.c			\
			src/builtins/env/setenv.c			\
			src/builtins/env/unsetenv.c			\
			src/builtins/env/env.c				\
			src/builtins/env/utils.c			\
			src/builtins/env/init.c				\
			src/builtins/cd.c					\
			src/builtins/echo.c					\
			src/builtins/exit.c					\
			src/builtins/which.c				\
			src/builtins/alias/alias.c			\
			src/builtins/alias/unalias.c		\
			src/builtins/alias/find_cmd.c		\
			src/builtins/repeat.c				\
			src/redirect/parse_cmd.c		\
			src/redirect/manage_separator.c			\
			src/redirect/utils.c			\

OBJ		:= $(SRC:.c=.o)

CFLAGS	:=	-Iinclude -W -Wall -Wshadow -Wextra

LDFLAGS	:=	-Llib/my -lmy

LIB		:=	lib/my/libmy.a

all: $(LIB) $(NAME)

$(LIB):
	make -C lib/my

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	make clean -C lib/my

fclean: clean
	$(RM) $(NAME)
	make fclean -C lib/my

re: fclean all

.PHONY: clean fclean re
