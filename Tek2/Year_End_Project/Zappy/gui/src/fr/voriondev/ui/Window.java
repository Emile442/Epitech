package fr.voriondev.ui;

import fr.voriondev.Zappy;
import fr.voriondev.network.PacketManager;
import fr.voriondev.ui.panels.BeforeGamePanel;
import fr.voriondev.ui.panels.MenuPanel;
import fr.voriondev.ui.panels.SettingsPanel;

import javax.swing.*;
import java.awt.*;

public class Window extends JFrame
{
    public Zappy zappy;

    public MenuPanel menuPanel;
    public SettingsPanel settingsPanel;
    public BeforeGamePanel beforeGamePanel;

    public Window()
    {
        this.zappy = Zappy.getInstance();

        this.menuPanel = new MenuPanel();
        this.settingsPanel = new SettingsPanel();
        this.beforeGamePanel = new BeforeGamePanel();

        this.setSize(800, 600);
        this.setBackground(Color.BLACK);
        this.setTitle("Zappy Game");
        this.setResizable(false);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);

        this.setContentPane(this.menuPanel);
    }

    public MenuPanel getMenuPanel()
    {
        return (this.menuPanel);
    }

    public SettingsPanel getSettingsPanel()
    {
        return (this.settingsPanel);
    }

    public BeforeGamePanel getBeforeGamePanel()
    {
        return (this.beforeGamePanel);
    }

    public void showFrame()
    {
        this.setVisible(true);
    }

}
