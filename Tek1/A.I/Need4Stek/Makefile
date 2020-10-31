##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/main_loop.c		\
		src/get_command.c	\
		src/start_simulation.c	\
		src/rotation_car.c	\
		src/get_info_lidar.c	\
		src/slow_down_speed.c

NAME	=	ai

LIB	=	-lm -L./lib/my/ -lmy

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I ./include/ -g

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ./lib/my/
		$(CC) -o $(NAME) $(OBJ) $(LIB) $(LDFLAGS)

tests_run:
		make -C ./tests/

clean:
		rm -f $(OBJ)
		make clean -C ./lib/my/

fclean:		clean
		make fclean -C ./lib/my/
		rm -f $(NAME)

re:		fclean all
