package fr.fedocker.pong.gui;

import fr.fedocker.pong.Pong;
import fr.fedocker.pong.utils.Logger;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;
import java.util.HashSet;
import java.util.Random;

public class GamePanel extends JPanel implements KeyListener, ActionListener
{

    public Pong game;
    private Timer t = new Timer(5, this);

    public int width, height;
    private boolean start;

    private HashSet<String> keys = new HashSet<String>();

    private int padW = 20, padH = 160, padInset = 10, padSpeed = 3;
    private int leftPadX, leftPadY, rightPadX, rightPadY;
    private int scoreLeft, scoreRight;

    private double ballX, ballY, velX = 1, velY = 1, ballSize = 20, ballSpeed = 2;

    public GamePanel(Pong p) {
        game = p;
        addKeyListener(this);
        setFocusable(true);
        this.requestFocusInWindow();
        start = true;
        t.setInitialDelay(100);
        t.start();
        this.setBackground(Color.black);
        scoreLeft = 0;
        scoreRight = 0;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;
        height = getHeight();
        width = getWidth();

        if (start) {
            leftPadX = 10;
            rightPadX = width - padW - 10;
            leftPadY = height / 2 - 80;
            rightPadY = height / 2 - 80;
            ballX = width / 2 - ballSize / 2;
            ballY = height / 2 - ballSize / 2;
            ballSpeed = 1.5;
            start = false;
        }

        if (game.getConfigManager().getConfigValue("retroMode")) {
            Rectangle2D leftPad = new Rectangle(leftPadX, leftPadY, padW, padH);
            g2d.setPaint(Color.white);
            g2d.fill(leftPad);

            Rectangle2D rightPad = new Rectangle(rightPadX, rightPadY, padW, padH);
            g2d.setPaint(Color.white);
            g2d.fill(rightPad);

            Ellipse2D ball = new Ellipse2D.Double(ballX, ballY, ballSize, ballSize);
            g2d.setPaint(Color.white);
            g2d.fill(ball);
        }
        else {
            g.drawImage(game.getResourceManager().getBackground(), 0, 0, null);
            g.drawImage(game.getResourceManager().getPad(), leftPadX, leftPadY, padW, padH, null);
            g.drawImage(game.getResourceManager().getPad(), rightPadX, rightPadY, padW, padH, null);
            g.drawImage(game.getResourceManager().getBall(), (int) ballX, (int) ballY, 20, 20, null);
        }

        String score = "SCORE";
        g2d.setFont(game.getResourceManager().getFont().deriveFont(72f));
        g2d.setPaint(Color.white);
        g2d.drawString(score, 330, 70);

        String scoreL = String.valueOf(scoreLeft);
        g2d.setFont(game.getResourceManager().getFont().deriveFont(48f));
        g2d.setPaint(Color.white);
        g2d.drawString(scoreL, 150, 100);

        String scoreR = String.valueOf(scoreRight);
        g2d.setFont(game.getResourceManager().getFont().deriveFont(48f));
        g2d.setPaint(Color.white);
        g2d.drawString(scoreR, 600, 100);
    }

    @Override
    public void actionPerformed(ActionEvent e)
    {
        if (ballY < 0 || ballY + ballSize > height)
            velY = -velY;

        if (ballX + ballSize > width) {
            velX = -velX;
            ++scoreLeft;
            start = true;
        }

        if (ballX < 0) {
            velX = -velX;
            ++scoreRight;
            start = true;
        }

        if (ballX <= 10 + padW && velX < 0)
            if(ballY >= leftPadY && ballY <= leftPadY + padH) {
                velX = -velX;
                increaseBallSpeed();
            }

        if (ballX + ballSize >= width - 10 - padW && velX > 0)
            if (ballY >= rightPadY && ballY <= rightPadY + padH) {
                velX = -velX;
                increaseBallSpeed();
            }

        ballX += velX * ballSpeed;
        ballY += velY * ballSpeed;

        if (keys.size() >= 1) {
            if (keys.contains("LEFT_UP")) {
                leftPadY -= (leftPadY > 0) ? padSpeed : 0;
            }
            if (keys.contains("LEFT_DOWN")) {
                leftPadY += (leftPadY < height - padH) ? padSpeed : 0;
            }
            if (keys.contains("RIGHT_UP") && !game.getConfigManager().getConfigValue("enableAI")) {
                rightPadY -= (rightPadY > 0) ? padSpeed : 0;
            }
            if (keys.contains("RIGHT_DOWN") && !game.getConfigManager().getConfigValue("enableAI")) {
                rightPadY += (rightPadY < height - padH) ? padSpeed : 0;
            }
        }

        if(game.getConfigManager().getConfigValue("enableAI")) {
            double delta = ballY - rightPadY;
            if (delta > 0) {
                rightPadY += (rightPadY < height - padH) ? padSpeed : 0;
            }
            else if (delta < 0) {
                rightPadY -= (rightPadY > 0) ? padSpeed : 0;
            }
        }
        repaint();
        this.grabFocus();
    }

    @Override
    public void keyTyped(KeyEvent e) {}

    @Override
    public void keyPressed(KeyEvent e) {
        int code = e.getKeyCode();
        switch (code) {
            case KeyEvent.VK_UP:
                keys.add("RIGHT_UP");
                break;
            case KeyEvent.VK_DOWN:
                keys.add("RIGHT_DOWN");
                break;
            case KeyEvent.VK_Z:
                keys.add("LEFT_UP");
                break;
            case KeyEvent.VK_S:
                keys.add("LEFT_DOWN");
                break;
            case KeyEvent.VK_ESCAPE:
                game.getWindow().exitGame(this);
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {
        int code = e.getKeyCode();
        switch (code) {
            case KeyEvent.VK_UP:
                keys.remove("RIGHT_UP");
                break;
            case KeyEvent.VK_DOWN:
                keys.remove("RIGHT_DOWN");
                break;
            case KeyEvent.VK_Z:
                keys.remove("LEFT_UP");
                break;
            case KeyEvent.VK_S:
                keys.remove("LEFT_DOWN");
                break;
        }
    }

    private void increaseBallSpeed()
    {
            if(ballSpeed < 4) {
                ballSpeed = ballSpeed + (ballSpeed / 6);
                Logger.info("Ball Speed: " + ballSpeed);
            }
            if(ballSpeed >= 4 && padSpeed == 3) {
                padSpeed += 2;
                Logger.info("Pad Speed: " + padSpeed);
            }
    }
}
