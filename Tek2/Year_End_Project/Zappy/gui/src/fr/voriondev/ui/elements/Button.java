package fr.voriondev.ui.elements;

import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.CompoundBorder;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;
import java.awt.*;

public class Button extends JButton {

    public Button(String label, int x, int y)
    {
        super(label);
        this.setForeground(Color.BLACK);
        this.setBackground(Color.decode("#34495E"));
        this.setOpaque(true);
        setFocusPainted(false);
        setBorderPainted(false);

        Border compound = new CompoundBorder(
            new LineBorder(Color.BLACK),
            new EmptyBorder(5, 15, 5, 15)
        );
        this.setBorder(compound);
        this.setBounds(x, y, 200, 50);
    }

}
