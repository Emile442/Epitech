package fr.voriondev.network;

import java.util.HashMap;
import java.util.Map;

import fr.voriondev.network.commands.ICommand;
import fr.voriondev.network.commands.ConnectedCommand;
import fr.voriondev.network.commands.TchatCommand;
import fr.voriondev.network.commands.UnknownCommand;

public class CommandsManager {

    private static CommandsManager instance;
    private final static Map<String, ICommand> map = new HashMap<String, ICommand>();

    CommandsManager()
    {
        instance = this;
        map.put("WELCOME", new ConnectedCommand());
        map.put("ko", new UnknownCommand());
    }

    public static CommandsManager getInstance()
    {
        return (instance);
    }

    public ICommand getMethod(String key)
    {
        return map.get(key);
    }
}
