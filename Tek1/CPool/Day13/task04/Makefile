##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## MAKE
##

SRC = 	my_window.c \
		main.c \

NAME = window

CFLAGS	=	-I include/

LDFLAGS =	-lcsfml-graphics -lcsfml-window -lcsfml-system

CC		= 	gcc

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME):		$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
clean:
		rm -rf $(OBJ)
fclean: clean
		rm -rf $(NAME)
re: fclean all