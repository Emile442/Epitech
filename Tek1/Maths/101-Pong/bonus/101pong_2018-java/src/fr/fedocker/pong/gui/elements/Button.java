package fr.fedocker.pong.gui.elements;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class Button extends JButton implements MouseListener
{

    public Button(String name)
    {
        this.setText(name);
        this.setForeground(Color.white);
        this.setBorderPainted(false);
        this.setVisible(true);
        addMouseListener(this);
    }

    public void mouseClicked(MouseEvent e) { }

    public void mousePressed(MouseEvent e) { }

    public void mouseReleased(MouseEvent e) { }

    public void mouseEntered(MouseEvent e) {
        if(e.getSource() == this)
            this.setForeground(Color.yellow);
    }


    public void mouseExited(MouseEvent e) {
        if(e.getSource() == this)
            this.setForeground(Color.white);
    }

}
