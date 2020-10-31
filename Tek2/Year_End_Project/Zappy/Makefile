##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## Makefile
##

all: ai server

ai:
	make -C ./ai
	cp ai/zappy_ai .

server:
	make -C ./server
	cp server/zappy_server .

gui:
	make -C ./gui
	cp gui/zappy_gui.jar .

clean:
	make clean -C ./ai
	make clean -C ./server

fclean: clean
	make fclean -C ./ai
	make fclean -C ./server
	$(RM) zappy_server zappy_ai

tests_run: clean
	#make tests_run -C ./ai
	make tests_run -C ./server

re: fclean all

.PHONY: all clean fclean re ai server gui
