package fr.voriondev.ui.panels;

import fr.voriondev.Zappy;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MenuPanel extends JPanel implements ActionListener
{
    public Zappy zappy;
    public Button settingsButton;

    public MenuPanel()
    {
        this.zappy = Zappy.getInstance();

        this.setBackground(Color.BLACK);
        this.setOpaque(true);
        this.setLayout(null);

        this.settingsButton = new Button("Play");
        this.settingsButton.setBounds(300, 275, 200, 50);
        this.settingsButton.addActionListener(this);
        this.add(settingsButton);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == this.settingsButton) {
            this.setVisible(false);
            this.zappy.getWindow().setContentPane(new BeforeGamePanel());
        }
    }
}
