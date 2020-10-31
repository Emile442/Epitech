
BIN_NAME	=	101pong

all:
	echo "#!/usr/bin/env php" > $(BIN_NAME)
	cat $(BIN_NAME).php >> $(BIN_NAME)
	chmod 711 $(BIN_NAME)

re: fclean all

clean:
	rm -f $(BIN_NAME)

fclean:
	rm -f $(BIN_NAME)
