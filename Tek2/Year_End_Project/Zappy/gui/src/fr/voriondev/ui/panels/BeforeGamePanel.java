package fr.voriondev.ui.panels;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import fr.voriondev.Zappy;
import fr.voriondev.network.PacketManager;
import fr.voriondev.ui.elements.Button;

public class BeforeGamePanel extends JPanel implements ActionListener
{
    PacketManager packetManager;

    JTextField ip;
    JTextField port;
    Button loginBtn;

    public BeforeGamePanel()
    {
        this.setBackground(Color.WHITE);
        this.setOpaque(true);
        this.setLayout(null);

        JLabel ipLabel = new JLabel("Server host");
        ipLabel.setBounds(220, 250, 150, 30);
        this.add(ipLabel);

        ip = new JTextField();
        ip.setBounds(300,250, 200,30);
        this.add(ip);

        JLabel portLabel = new JLabel("Server port");
        portLabel.setBounds(220, 300, 150, 30);
        this.add(portLabel);

        port = new JTextField();
        port.setBounds(300,300, 200,30);
        this.add(port);

        loginBtn = new Button("Valider", 300 , 350);
        loginBtn.addActionListener(this);
        this.add(loginBtn);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == this.loginBtn) {
            if (ip.getText().length() == 0 || port.getText().length() == 0)
                return;
            System.out.printf("%s - %s", ip.getText(), port.getText());
            this.packetManager = new PacketManager(ip.getText(), Integer.parseInt(port.getText()));
            Zappy.getInstance().setPacketManager(this.packetManager);
            try {
                Zappy.getInstance().getPacketManger().connect();
                Zappy.getInstance().getPacketManger().listen();
            } catch (Exception e1) {
                return;
            }
            this.setVisible(false);
            Zappy.getInstance().getWindow().setContentPane(new GamePanel());
        }
    }
}
