##
## EPITECH PROJECT, 2020
## MyTeams
## File description:
## Makefile
##

all: cli server

cli:
	make -C ./cli
	cp cli/myteams_cli .

server:
	make -C ./server
	cp server/myteams_server .

clean:
	make clean -C ./cli
	make clean -C ./server

fclean: clean
	make fclean -C ./cli
	make fclean -C ./server
	rm myteams_server myteams_cli

tests_run: clean
	#make tests_run -C ./cli
	make tests_run -C ./server

re: fclean all

.PHONY: all clean fclean re cli server
