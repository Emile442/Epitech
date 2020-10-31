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

public class OptionsPanel extends JPanel implements ActionListener
{
    public Pong game;
    public JLabel gameTitle;
    public Button modeBtn;
    public Button retroBtn;
    public Button returnBtn;

    public OptionsPanel(Pong p)
    {
        game = p;
        setBackground(Color.black);
        setOpaque(true);
        setLayout(null);

        gameTitle = new JLabel("101pong");
        gameTitle.setFont(game.getResourceManager().getFont().deriveFont(72f));
        gameTitle.setForeground(Color.white);
        gameTitle.setBounds(290, 20, 300, 72);
        this.add(gameTitle);

        modeBtn = new Button("MODE: 1P");
        modeBtn.setFont(game.getResourceManager().getFont().deriveFont(48f));
        modeBtn.setBounds(280, 200, 240, 48);
        modeBtn.addActionListener(this::actionPerformed);
        this.add(modeBtn);

        retroBtn = new Button("RETRO MODE: OFF");
        retroBtn.setFont(game.getResourceManager().getFont().deriveFont(48f));
        retroBtn.setBounds(255, 260, 300, 48);
        retroBtn.addActionListener(this::actionPerformed);
        this.add(retroBtn);

        returnBtn = new Button("RETURN");
        returnBtn.setFont(game.getResourceManager().getFont().deriveFont(48f));
        returnBtn.setBounds(310, 320, 180, 48);
        returnBtn.addActionListener(this::actionPerformed);
        this.add(returnBtn);
    }

    @Override
    public void actionPerformed(ActionEvent e)
    {
        if (e.getSource() == this.modeBtn) {
            String btnText = game.getConfigManager().getConfigValue("enableAI") ? "MODE: 2P" : "MODE: 1P";
            this.modeBtn.setText(btnText);
            game.getConfigManager().setConfigValue("enableAI", !game.getConfigManager().getConfigValue("enableAI"));
        }
        if (e.getSource() == this.retroBtn) {
            String btnText = game.getConfigManager().getConfigValue("retroMode") ? "RETRO MODE: OFF" : "RETRO MODE: ON";
            this.retroBtn.setText(btnText);
            game.getConfigManager().setConfigValue("retroMode", !game.getConfigManager().getConfigValue("retroMode"));
        }
        else if (e.getSource() == this.returnBtn)
            game.getWindow().switchPanels(this);
    }

    public void paintComponent(Graphics g)
    {
        g.drawImage(game.getResourceManager().getBackground(), 0, 0, null);
    }

}
