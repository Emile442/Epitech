##
## EPITECH PROJECT, 2020
## CPP_POOL
## File description:
## Makefile
##

TEST_NAME		=	unit_tests

CXXFLAGS		=	-W -Wall -Wextra -Wshadow -I ex00/ -I ex01/

SRC_TEST		=	ex00/tests/Skat_tests.cpp		\
					ex01/tests/Parts_tests.cpp		\
					ex01/tests/KoalaBot_tests.cpp	\

SRC_TESTED		=	ex00/Skat.cpp		\
					ex01/Parts.cpp		\
					ex01/KoalaBot.cpp	\

RM				=	rm -f

CC				=	g++

TEST_FLAGS	=	-lcriterion --coverage

clean:
				$(RM) *.gc*

fclean: 		clean
				$(RM) $(TEST_NAME)

tests_run: 		clean
				$(CC) -o $(TEST_NAME) $(CXXFLAGS) $(SRC_TEST) $(SRC_TESTED) $(TEST_FLAGS)
				./unit_tests
				gcovr --exclude ex00/tests --exclude ex01/tests