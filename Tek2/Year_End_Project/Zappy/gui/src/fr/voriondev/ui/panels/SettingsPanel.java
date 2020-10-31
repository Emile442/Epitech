package fr.voriondev.ui.panels;

import javax.swing.*;
import java.awt.*;

public class SettingsPanel extends JPanel {

    public SettingsPanel()
    {
        this.setBackground(Color.BLUE);
        this.setOpaque(true);
        this.setLayout(null);

        JButton btn = new JButton("Bouton");
        btn.setBounds(50, 20, 100, 20);
        this.add(btn);
    }

}
