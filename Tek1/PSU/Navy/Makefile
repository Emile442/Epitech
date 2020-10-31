##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for navy
##

NAME	=	navy

SRC	=	src/map/check_file_errors.c	\
		src/map/get_map.c		\
		src/map/load_file_in_mem.c	\
		src/map/print_map.c		\
		src/map/wait_for_attack.c	\
		src/print_game.c		\
		src/get_usr_input.c		\
		src/client/client.c		\
		src/server/server.c		\
		src/signal/stock_bits.c		\
		src/signal/stock_pid.c		\
		src/signal/wait_signal.c	\
		src/signal/send_signal.c	\
		src/map/gameover.c		\
		src/map/utils.c			\
		src/map/verify_local_attack.c	\
		src/map/verify_receive_attack.c	\
		src/main.c			\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-W -Wall -Wextra -Wshadow	\
		-Iinclude			\

LIB	=	my

LIB_PATH=	lib/my

LDFLAGS	=	-L$(LIB_PATH) -l$(LIB)

CC	=	gcc

RM	=	rm -f

all	:
		make -C $(LIB_PATH)
		make $(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean	:
		make clean -C $(LIB_PATH)
		make clean -C tests
		$(RM) $(OBJ)

fclean	:	clean
		make fclean -C $(LIB_PATH)
		make fclean -C tests
		$(RM) $(NAME)

re	:	fclean all
		make re -C $(LIB_PATH)

tests_run	:
			make -C $(LIB_PATH)
			make -C tests

.PHONY	:	clean fclean re
