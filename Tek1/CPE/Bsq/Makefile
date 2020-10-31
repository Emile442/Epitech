##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## BSQ
##

NAME	=	bsq

SRC		=	main.c					\
			src/bsq.c				\
			src/fs_file.c			\
			src/maths_utils.c		\
			src/maps_transform.c	\
			src/maps_info.c

OBJ 	=	$(SRC:.c=.o)

CFLAGS	=	-I ./include

LDFLAGS	=	-L./lib/my -lmy

all: $(NAME)
	
$(NAME): $(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re