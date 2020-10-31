package fr.voriondev;

import fr.voriondev.network.PacketManager;
import fr.voriondev.ui.Window;

public class Zappy
{
    public static Zappy instance;
    private final Window frame;
    private PacketManager packetManager;

    Zappy()
    {
        instance = this;
        this.frame = new Window();
        this.frame.showFrame();
    }

    public static Zappy getInstance()
    {
        return (instance);
    }

    public Window getWindow()
    {
        return (this.frame);
    }

    public PacketManager getPacketManger()
    {
        return (this.packetManager);
    }

    public void setPacketManager(PacketManager packetManager)
    {
        this.packetManager = packetManager;
    }

    public static void main(String[] args)
    {
        new Zappy();
    }
}
