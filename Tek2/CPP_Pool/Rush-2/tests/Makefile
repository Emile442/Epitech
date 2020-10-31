##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	test_Box.cpp	\
		../Box.cpp	\
		../Wrap.cpp	\
		test_LittlePony.cpp	\
		../LittlePony.cpp	\
		../Toy.cpp	\
		../GiftPaper.cpp	\
		../Object.cpp	\
		../Teddy.cpp	\
		test_Teddy.cpp	\
		test_Wrap.cpp	\
		../ConveyorBelt.cpp	\
##		test_GiftPaper.cpp	\
##		test_Object.cpp	\
##		test_Toy.cpp	\

NAME	=	unit_tests

OBJ	=	$(SRC:.cpp=.o)

CXXFLAGS	=	-I ./ -W -Wextra -Wall -coverage

LDFLAGS	=	-lcriterion -lgcov

CC	=	g++

all:		$(NAME)

$(NAME):
		$(CC) -o $(NAME) $(SRC) $(CXXFLAGS) $(LDFLAGS)
		mv $(NAME) ../
		../$(NAME)

clean:
		touch testgctest
		rm -f $(OBJ)
		rm *gc*

fclean:		clean
		rm -f ../$(NAME)

re:		fclean all
