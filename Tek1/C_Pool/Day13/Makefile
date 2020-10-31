##
## EPITECH PROJECT, 2018
## MAKEFILE
## File description:
## MAKE
##

SRC = 	my_window.c \
		draw.c \
		main.c \

NAME = window

CFLAGS	=	-I include/

LDFLAGS =	-lcsfml-graphics -lcsfml-window -lcsfml-system

CC		= 	gcc

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME):		$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)
		$(MAKE) -C task04 all
clean:
		rm -rf $(OBJ)
		$(MAKE) -C task04 clean
fclean: clean
		rm -rf $(NAME)
		$(MAKE) -C task04 fclean
re: fclean all