BIN_NAME	=	204ducks

all:
	echo "#!/usr/bin/env php" > $(BIN_NAME)
	cat maths.php >> $(BIN_NAME)
	chmod 711 $(BIN_NAME)

re: fclean all

clean:
	rm -f $(BIN_NAME)

fclean:
	rm -f $(BIN_NAME)
