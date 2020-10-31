package fr.fedocker.pong.gui;

import fr.fedocker.pong.Pong;

import javax.imageio.ImageIO;
import javax.swing.*;

import fr.fedocker.pong.gui.elements.Button;
import fr.fedocker.pong.utils.Logger;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.InputStream;

public class MenuPanel extends JPanel implements ActionListener
{
    public Pong game;
    public JLabel gameTitle;
    public Button playBtn;
    public Button optionsBtn;
    public Button quitBtn;

    public MenuPanel(Pong p) {
        game = p;
        setBackground(Color.black);
        setOpaque(true);
        setLayout(null);

        gameTitle = new JLabel("101pong");
        gameTitle.setFont(game.getResourceManager().getFont().deriveFont(72f));
        gameTitle.setForeground(Color.white);
        gameTitle.setBounds(290, 20, 300, 72);
        this.add(gameTitle);

        playBtn = new Button("PLAY");
        playBtn.setFont(game.getResourceManager().getFont().deriveFont(48f));
        playBtn.setBounds(310, 200, 180, 48);
        playBtn.addActionListener(this::actionPerformed);
        this.add(playBtn);

        optionsBtn = new Button("OPTIONS");
        optionsBtn.setFont(game.getResourceManager().getFont().deriveFont(48f));
        optionsBtn.setBounds(307, 260, 180, 48);
        optionsBtn.addActionListener(this::actionPerformed);
        this.add(optionsBtn);

        quitBtn = new Button("QUIT");
        quitBtn.setFont(game.getResourceManager().getFont().deriveFont(48f));
        quitBtn.setBounds(310, 320, 180, 48);
        quitBtn.addActionListener(this::actionPerformed);
        this.add(quitBtn);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == this.playBtn)
            game.getWindow().startGame();
        else if (e.getSource() == this.optionsBtn)
            game.getWindow().switchPanels(this);
        else if (e.getSource() == this.quitBtn) {
            Logger.info("Exiting game..");
            System.exit(0);
        }
    }

    public void paintComponent(Graphics g)
    {
        g.drawImage(game.getResourceManager().getBackground(), 0, 0, null);
    }

}