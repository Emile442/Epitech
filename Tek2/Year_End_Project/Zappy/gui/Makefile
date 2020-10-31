JAVAC   	=   javac

JAR			= 	zappy_gui.jar

sources     =   src/fr/voriondev/network/commands/ICommand.java         \
                src/fr/voriondev/network/commands/ConnectedCommand.java \
                src/fr/voriondev/network/commands/TchatCommand.java     \
               	src/fr/voriondev/network/commands/UnknownCommand.java   \
                src/fr/voriondev/network/CommandsManager.java           \
                src/fr/voriondev/network/PacketManager.java             \
                src/fr/voriondev/ui/elements/Button.java                \
                src/fr/voriondev/ui/panels/BeforeGamePanel.java         \
                src/fr/voriondev/ui/panels/GamePanel.java               \
                src/fr/voriondev/ui/panels/MenuPanel.java               \
                src/fr/voriondev/ui/panels/SettingsPanel.java           \
                src/fr/voriondev/ui/Window.java                         \
                src/fr/voriondev/utils/Utils.java                       \
                src/fr/voriondev/Zappy.java
                
classes     =   $(sources:.java=.class)

%.class : %.java
	$(JAVAC) -cp src/ -d out -target 8 -source 8 -Xlint:-options $<

all: $(classes)
	jar -cvmf MANIFEST.MF $(JAR) -C out/ .

clean:
	$(RM) $(classes)
	$(RM) -r out/

fclean: clean
	$(RM) $(JAR)

re: fclean all

run:
	java -jar $(JAR)

.PHONY: all clean fclean re run