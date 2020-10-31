package fr.voriondev.network.commands;

public class UnknownCommand implements ICommand {
    @Override
    public void handle(String[] cmd) {
        System.out.println("Commande inconnue");
    }
}
