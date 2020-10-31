package fr.voriondev.network;

import fr.voriondev.network.commands.ICommand;
import fr.voriondev.utils.Coordinates;
import fr.voriondev.utils.Utils;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;
import java.util.concurrent.atomic.AtomicBoolean;

public class PacketManager
{
    public static PacketManager instance;

    private String host;
    private int port;

    private Socket socket;
    private boolean isConnected = false;
    private boolean isFinished;
    private CommandsManager commandsManager;
    private ArrayList<Coordinates> coords = new ArrayList<>();

    public PacketManager(String host, int port)
    {
        instance = this;
        this.host = host;
        this.port = port;
        this.commandsManager = new CommandsManager();
    }

    private void getPlayerCoordinates(String input)
    {
        ArrayList<Coordinates> arrayList = new ArrayList<>();
        String[] arr = input.split(";");
        String teamName = "";
        Integer x = 0;
        Integer y = 0;
        Coordinates coor = new Coordinates();

        arrayList.clear();
        for (String str : arr) {
            teamName = str.substring(str.indexOf(":"));
            if (teamName.equals(""))
                return;
            x = Integer.parseInt(str.substring(str.indexOf(":") + 1, str.indexOf(",")));
            y = Integer.parseInt(str.substring(str.indexOf(",") + 1));
            coor.setX(x);
            coor.setY(y);
            arrayList.add(coor);
        }
        this.coords = arrayList;
    }

    public ArrayList<Coordinates> listCoordinates()
    {
        return (coords);
    }

    public void connect()
    {
        try {
            socket = new Socket(host, port);
            System.out.format("[Client] Attempting to connect to the server %s:%d\n", host, port);
            isConnected = true;
        } catch (IOException e) {
            System.err.println("[Client] Unable to connect to the server: " + e.getLocalizedMessage());
            isConnected = false;
        }
    }

    public void listen()
    {
        final Thread inThread = new Thread(() -> {
            Scanner in = null;
            try {
                in = new Scanner(socket.getInputStream());
                for (String line = in.nextLine(); !isFinished; line = in.nextLine()) {
                    // System.out.println("[Server]: " + line);
                    String[] cmd = Utils.parseStr(line);
                    ICommand command = CommandsManager.getInstance().getMethod(cmd[0]);
                    if (null != command) {
                        command.handle(cmd);
                    } else if (cmd[0].contains(",") && cmd[0].contains(":")) {
                        System.err.println(cmd[0]);
                        getPlayerCoordinates(cmd[0]);
                    }
                    else {
                        System.err.println("-----------------------------------");
                        System.err.println("[Server] " + line);
                        System.err.println("-----------------------------------");
                    }
                }
            } catch (Exception e) {
                System.err.println("[Client] Connection interrupted with the server");
                try {
                    throw new Exception("");
                } catch (Exception exception) {}
            } finally {
                if (in != null) {
                    in.close();
                }
            }
        });
        inThread.start();
    }

    public void send(String message)
    {
        if (!isConnected || socket.isClosed())
            return;
        try {
            PrintWriter out = new PrintWriter(socket.getOutputStream());
            out.println(message);
            out.flush();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public boolean isConnected()
    {
        return socket.isConnected() && !socket.isClosed();
    }

    public void disconnect()
    {
        try {
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static PacketManager getInstance()
    {
        return (instance);
    }

}
