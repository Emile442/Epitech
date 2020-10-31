##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Automatic compilation
##

NAME 	= 	myteams_server

TEST_NAME = unit_tests

SRC		=	src/main.c														\
			src/utils/error_handling.c 										\
			src/utils/parse_str.c 											\
			src/utils/usage.c 												\
			src/utils/uuid.c 												\
			src/utils/clean_cmd.c 											\
			src/utils/rfc_str.c 											\
			src/network/server.c 											\
			src/network/init.c 												\
			src/network/client.c 												\
			src/core/middleware/auth.c										\
			src/core/dispatch.c 											\
			src/core/create.c												\
			src/core/info.c													\
			src/core/list.c													\
			src/core/response/sendto.c 										\
			src/utils/cmd_parsing.c											\
			src/core/commands/cmd_ping.c									\
			src/core/commands/sessions/cmd_login.c							\
			src/core/commands/sessions/cmd_logout.c							\
			src/core/commands/sessions/cmd_users.c							\
			src/core/commands/sessions/cmd_user.c							\
			src/core/commands/sessions/cmd_info.c							\
			src/core/commands/sessions/utils/list.c							\
			src/core/commands/sessions/utils/user.c							\
			src/core/commands/private_messages/cmd_messages.c 				\
			src/core/commands/private_messages/cmd_send.c 					\
			src/core/commands/private_messages/utils/conversations_list.c 	\
			src/core/commands/private_messages/utils/messages_list.c		\
			src/core/commands/teams/utils/teams_list.c 						\
			src/core/commands/teams/cmd_create.c 							\
			src/core/commands/teams/cmd_list.c 								\
			src/core/commands/teams/cmd_info.c 								\
			src/core/commands/teams/subscribers/cmd_subscribe.c 			\
			src/core/commands/teams/subscribers/cmd_unsubscribe.c 			\
			src/core/commands/teams/subscribers/cmd_list.c 					\

SRC_TESTS = tests/test_parsing_command.c									\
			src/utils/cmd_parsing.c

OBJ 	=	$(SRC:.c=.o)

CC		= 	gcc

CFLAGS	=	-W -Wall -Wno-deprecated -I ./includes -g

LDFLAGS =	-L../libs/myteams -lmyteams -luuid

TESTSFLAGS = -lcriterion --coverage -I ./includes

all: $(NAME)

$(NAME): $(OBJ)
	gcc -w -o $(NAME) $(OBJ) $(LCFLAGS) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *.gc*

fclean:	clean
	$(RM) $(NAME)

tests_run: clean
	gcc -o $(TEST_NAME) $(SRC_TESTS) $(LCFLAGS) $(LDFLAGS) $(TESTSFLAGS)
	./$(TEST_NAME)
	gcovr --exclude tests

re:	fclean all

.PHONY: all clean fclean re
