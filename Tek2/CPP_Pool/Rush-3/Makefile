##
## EPITECH PROJECT, 2020
## Makefile - Boiler Template
## File description:
## Build App
##

SRC		=	src/main.cpp											\
			app/Class/GraphicMonitorDisplay.cpp	\
			app/Interface/IMonitorModule.cpp						\
			app/Interface/IMonitorSubModule.cpp						\
			app/Interface/IMonitorDisplay.cpp						\
			app/Class/GraphicElement.cpp						\
			src/Modules/OSInfo/OSInfoModule.cpp						\
			src/Modules/OSInfo/SubModules/NameSubModule.cpp			\
			src/Modules/OSInfo/SubModules/VersionSubModule.cpp		\
			src/Modules/OSInfo/SubModules/OsVersionSubModule.cpp	\
			src/Modules/HostInfo/HostInfoModule.cpp					\
			src/Modules/HostInfo/SubModules/NameSubModule.cpp		\
			src/Modules/HostInfo/SubModules/UsernameSubModule.cpp	\
			src/Modules/DateTime/DateTimeModule.cpp					\
			src/Modules/DateTime/SubModules/DateSubModule.cpp		\
			src/Modules/DateTime/SubModules/TimeSubModule.cpp		\
			src/Modules/RamInfo/RamInfoModule.cpp					\
            src/Modules/RamInfo/SubModules/TotalSubModule.cpp		\
            src/Modules/RamInfo/SubModules/AvailableSubModule.cpp	\
            src/Modules/CpuInfo/CpuInfoModule.cpp					\
            src/Modules/CpuInfo/SubModules/UsageSubModule.cpp		\
            src/Modules/NetworkInfo/NetworkInfoModule.cpp			\
            src/Modules/NetworkInfo/SubModules/UpSubModule.cpp		\
            src/Modules/NetworkInfo/SubModules/DownSubModule.cpp		\
            src/Graphic/displayModules.cpp	\
            src/Text/Ncurses.cpp


CFLAGS	=	-Wall -Wextra -Werror

LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lncurses

CC		=	g++

OBJS	=	$(SRC:.cpp=.o)

NAME	=	MyGKrellm

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	make -C tests
	./tests/unit-tests
	gcovr --exclude tests

.PHONY: all clean fclean re tests_run
