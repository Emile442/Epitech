package fr.fedocker.pong.gui;

import javax.swing.*;
import fr.fedocker.pong.Pong;
import fr.fedocker.pong.utils.Logger;
import java.awt.*;

public class Window extends JFrame
{

    public Pong game;
    public JPanel mainPanel;
    public MenuPanel menuPanel;
    public OptionsPanel optionsPanel;

    public Window(Pong g)
    {
        game = g;
    }

    public void openFrame()
    {
        menuPanel = new MenuPanel(game);
        optionsPanel = new OptionsPanel(game);
        mainPanel = new JPanel();

        JFrame frame = new JFrame();
        frame.setTitle("Pong");
        frame.setSize(800, 600);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);

        mainPanel.setLayout(new CardLayout());
        mainPanel.add(menuPanel);
        mainPanel.add(optionsPanel);
        frame.setContentPane(mainPanel);
        frame.setVisible(true);
    }

    public void switchPanels(JPanel current) {
        CardLayout cardLayout = (CardLayout) mainPanel.getLayout();
        if(current == menuPanel)
            cardLayout.next(mainPanel);
        else
            cardLayout.previous(mainPanel);
        Logger.info("Switching panel from panel: " + current.getClass().getSimpleName());
    }

    public void startGame() {
        CardLayout cardLayout = (CardLayout) mainPanel.getLayout();
        mainPanel.add(new GamePanel(game));
        cardLayout.last(mainPanel);
        Logger.info("Starting game !");
    }

    public void exitGame(JPanel panel) {
        CardLayout cardLayout = (CardLayout) mainPanel.getLayout();
        mainPanel.remove(panel);
        cardLayout.first(mainPanel);
        Logger.info("Exiting game !");
    }

}
