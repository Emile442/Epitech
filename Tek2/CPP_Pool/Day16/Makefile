##
## EPITECH PROJECT, 2020
## CPP_POOL
## File description:
## Makefile
##

TEST_NAME		=	unit_tests

CXXFLAGS		=	-W -Wall -Wextra -Wshadow -I ./ex00

SRC_TEST		=	tests/ex00_tests.cpp	\

SRC_TESTED		=	ex00/Parser.cpp

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
				gcovr --exclude tests