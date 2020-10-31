package fr.voriondev.network.commands;

public class ConnectedCommand implements ICommand {

    @Override
    public void handle(String[] cmd) {
        System.out.println("[Server] Connection established");
    }
}
