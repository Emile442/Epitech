##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## MyDefender
##

NAME	=	myftp

SRC		=	src/main.c 							\
			src/server/init.c 					\
			src/server/wait_connections.c 		\
			src/server/client/init.c 			\
			src/server/client/new.c 			\
			src/server/data/init.c 				\
			src/utils/error_message.c 			\
			src/utils/parse_str.c 				\
			src/utils/strlen_array.c 			\
			src/utils/rdm_number.c 				\
			src/ftp/dispatch.c 					\
			src/ftp/response.c 					\
			src/ftp/middleware/data_middleware.c\
			src/ftp/middleware/auth_middleware.c\
			src/ftp/commands/cmd_quit.c			\
			src/ftp/commands/cmd_auth.c			\
			src/ftp/commands/cmd_pwd.c			\
			src/ftp/commands/cmd_cwd.c			\
			src/ftp/commands/cmd_cdup.c			\
			src/ftp/commands/cmd_noop.c			\
			src/ftp/commands/cmd_help.c			\
			src/ftp/commands/cmd_port.c			\
			src/ftp/commands/cmd_pasv.c			\
			src/ftp/commands/cmd_list.c			\

OBJ 	=	$(SRC:.c=.o)

CC		= 	gcc

CFLAGS	=	-W -Wall -Wno-deprecated -I ./include

all: $(NAME)

$(NAME): $(OBJ)
	gcc -w -o $(NAME) $(OBJ) $(LCFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
