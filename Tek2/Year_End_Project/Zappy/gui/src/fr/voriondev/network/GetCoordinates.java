package fr.voriondev.network;

import fr.voriondev.Zappy;

import java.util.TimerTask;

public class GetCoordinates extends TimerTask {
    public void run() {
        Zappy.getInstance().getPacketManger().send("gui_players");
    }
}
