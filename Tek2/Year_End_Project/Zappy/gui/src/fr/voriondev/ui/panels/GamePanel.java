package fr.voriondev.ui.panels;

import fr.voriondev.Zappy;
import fr.voriondev.network.GetCoordinates;
import fr.voriondev.utils.Coordinates;

import java.awt.*;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.MouseInfo;
import java.awt.Point;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.awt.geom.AffineTransform;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Timer;
import javax.swing.JPanel;

public class GamePanel extends JPanel implements MouseWheelListener, MouseListener, MouseMotionListener {

    public static final Color BORDER = new Color(0, 102, 0);
    public static final Color CONTENT = new Color(20, 180, 20);

    public static final int NUM_ROWS = 30;
    public static final int NUM_COLS = 30;

    private double zoomFactor = 1;
    private double prevZoomFactor = 1;
    private boolean zoomer;
    private boolean dragger;
    private boolean released;
    private double xOffset = 0;
    private double yOffset = 0;
    private int xDiff;
    private int yDiff;
    private Point startPoint;
    private Timer timer;

    public GamePanel() {
        initComponent();
        Zappy.getInstance().getPacketManger().send("team1");
        Zappy.getInstance().getPacketManger().send("gui_players");
        timer = new Timer();
        timer.schedule(new GetCoordinates(), 0, 5000);
    }

    private void initComponent() {
        addMouseWheelListener(this);
        addMouseMotionListener(this);
        addMouseListener(this);
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);

        Graphics2D g2 = (Graphics2D) g;
        float thickness = 2;
        Stroke oldStroke = g2.getStroke();

        if (zoomer) {
            AffineTransform at = new AffineTransform();

            double xRel = MouseInfo.getPointerInfo().getLocation().getX() - getLocationOnScreen().getX();
            double yRel = MouseInfo.getPointerInfo().getLocation().getY() - getLocationOnScreen().getY();

            double zoomDiv = zoomFactor / prevZoomFactor;

            xOffset = (zoomDiv) * (xOffset) + (1 - zoomDiv) * xRel;
            yOffset = (zoomDiv) * (yOffset) + (1 - zoomDiv) * yRel;

            at.translate(xOffset, yOffset);
            at.scale(zoomFactor, zoomFactor);
            prevZoomFactor = zoomFactor;
            g2.transform(at);
            zoomer = false;
        }

        if (dragger) {
            AffineTransform at = new AffineTransform();
            at.translate(xOffset + xDiff, yOffset + yDiff);
            at.scale(zoomFactor, zoomFactor);
            g2.transform(at);

            if (released) {
                xOffset += xDiff;
                yOffset += yDiff;
                dragger = false;
            }

        }
        int rectWidth = getWidth() / NUM_COLS;
        int rectHeight = rectWidth;

        for (int i = 0; i < NUM_ROWS; i++) {
            for (int j = 0; j < NUM_COLS; j++) {
                int x = i * rectWidth;
                int y = j * rectHeight;
                g2.setStroke(new BasicStroke(thickness));
                g2.setColor(CONTENT);
                g2.fillRect(x, y, rectWidth, rectHeight);
                g2.setColor(BORDER);
                g2.drawRect(x, y, rectWidth, rectHeight);
                g2.setStroke(oldStroke);
            }
        }

        ArrayList<Coordinates> coords = Zappy.getInstance().getPacketManger().listCoordinates();
        for (Coordinates co : coords) {
            int x = (co.getX() - 1) * rectWidth;
            int y = (co.getY() - 1) * rectHeight;
            g2.setColor(Color.BLUE);
            g2.fillOval(x, y, rectWidth / 2, rectHeight / 2);
        }
    }

    @Override
    public void mouseWheelMoved(MouseWheelEvent e) {

        zoomer = true;

        if (e.getWheelRotation() < 0) {
            zoomFactor *= 1.1;
            repaint();
        }

        if (e.getWheelRotation() > 0) {
            zoomFactor /= 1.1;
            repaint();
        }
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        Point curPoint = e.getLocationOnScreen();
        xDiff = curPoint.x - startPoint.x;
        yDiff = curPoint.y - startPoint.y;

        dragger = true;
        repaint();

    }

    @Override
    public void mouseMoved(MouseEvent e) {}

    @Override
    public void mouseClicked(MouseEvent e) {}

    @Override
    public void mousePressed(MouseEvent e) {
        released = false;
        startPoint = MouseInfo.getPointerInfo().getLocation();
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        released = true;
        repaint();
    }

    @Override
    public void mouseEntered(MouseEvent e) {}

    @Override
    public void mouseExited(MouseEvent e) {}
}