package fr.voriondev.network.commands;

public class TchatCommand implements ICommand {
    @Override
    public void handle(String[] cmd) {
        for (int i = 1; i < cmd.length; i++) {
            System.out.print(cmd[i]);
            if (i != cmd.length - 1)
                System.out.print(" ");
        }
        System.out.print("\n");
    }
}
