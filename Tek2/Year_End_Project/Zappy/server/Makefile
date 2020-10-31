#
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Zappy Server
##

NAME 	= 	zappy_server

SRC		=	src/main.c 							\
			src/map/init_map.c					\
			src/map/link_map.c					\
			src/map/free_map.c					\
			src/map/utils_map.c					\
			src/map/create_resource.c			\
			src/map/generate_resources.c		\
			src/map/utils_pos_map.c				\
			src/network/create.c				\
			src/network/destroy.c				\
			src/network/loop.c					\
			src/network/socket.c				\
			src/network/start.c					\
			src/network/clients/handle.c		\
			src/network/clients/init.c			\
			src/network/clients/destroy.c		\
			src/network/clients/new.c			\
			src/network/clients/utils.c			\
			src/core/create.c					\
			src/core/destroy.c					\
			src/core/dispatch.c					\
			src/core/wait_time.c				\
			src/utils/send_to.c					\
			src/utils/parse_str.c				\
			src/utils/format_str.c				\
			src/utils/uuid.c					\
			src/commands/divers/cmd_ping.c		\
			src/commands/move/cmd_move.c		\
			src/commands/divers/cmd_time.c		\
			src/commands/divers/cmd_broadcast.c	\
			src/commands/cmd_look.c				\
			src/commands/teams/cmd_register.c	\
			src/commands/teams/cmd_elevation.c	\
			src/commands/teams/elevation_level.c \
			src/commands/cmd_inventory.c		\
			src/commands/cmd_fork.c				\
			src/commands/cmd_take_object.c		\
			src/option/init_server_option.c		\
			src/option/fill_args.c				\
			src/player/create_player.c			\
			src/player/destroy_player.c			\
			src/player/utils.c					\
			src/option/fill_args_bis.c			\
			src/player/inventory/inventory_utils.c	\
			src/player/player_reproduction.c 	\
			src/commands/gui/cmd_players.c 		\

OBJ 	=	$(SRC:.c=.o)

CC		= 	gcc

CFLAGS	=	-W -Wall -Wno-deprecated -I ./includes

LDFLAGS	= 	-luuid -lm

all: $(NAME)

$(NAME): $(OBJ)
	gcc -w -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
