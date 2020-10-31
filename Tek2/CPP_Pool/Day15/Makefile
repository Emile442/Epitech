##
## EPITECH PROJECT, 2020
## CPP_POOL
## File description:
## Makefile
##

TEST_NAME		=	unit_tests

CXXFLAGS		=	-W -Wall -Wextra -Wshadow -I ./ex00 -I ./ex01 -I ./ex02 -I ./ex03 -I ./ex04

SRC_TEST		=	tests/ex00_tests.cpp	\
					tests/ex01_tests.cpp	\
					tests/ex02_tests.cpp	\
					tests/ex03_tests.cpp	\
					tests/ex04_tests.cpp	\

SRC_TESTED		=	ex04/ex04.cpp

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