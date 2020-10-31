##
## EPITECH PROJECT, 2020
## CPP_POOL
## File description:
## Makefile
##

TEST_NAME		=	unit_tests

CXXFLAGS		=	-W -Wall -Wextra -Wshadow -I ./

SRC_TEST		=	tests/Character_tests.cpp	\
					tests/Warrior_tests.cpp		\
					tests/Mage_tests.cpp		\
					tests/Priest_tests.cpp		\

SRC_TESTED		=	Character.cpp	\
					Warrior.cpp		\
					Mage.cpp		\
					Priest.cpp		\

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