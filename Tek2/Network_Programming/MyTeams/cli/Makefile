##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Automatic compilation
##

NAME 	= 	myteams_cli

SRC		=	src/main.c 							\
			src/utils/error_handling.c			\
			src/utils/usage.c					\
			src/utils/parse_str.c					\
			src/network/init.c					\
			src/network/setup.c					\
			src/network/send.c					\
			src/network/recv.c					\
			src/network/bind.c					\
			src/core/loop.c						\
			src/core/prompt.c					\
			src/core/local/dispatch.c			\
			src/core/local/commands/command_quit.c			\
			src/core/local/commands/command_ping.c			\
			src/core/server/dispatch.c			\
			src/core/server/send.c				\
			src/core/server/commands/command_pong.c			\
			src/core/local/commands/command_log.c		\
			src/core/server/commands/command_users.c		\
			src/core/server/commands/command_message.c		\
			src/core/server/commands/command_error.c		\
			src/core/local/commands/commands.c		\


OBJ 	=	$(SRC:.c=.o)

CC		= 	gcc

CFLAGS	=	-W -Wall -Wno-deprecated -I ./includes -g

LDFLAGS =	-L../libs/myteams -luuid -lmyteams

all: $(NAME)

$(NAME): $(OBJ)
	gcc -w -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
