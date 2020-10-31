package fr.fedocker.pong.game;

import fr.fedocker.pong.Pong;
import fr.fedocker.pong.utils.Logger;

import javax.imageio.ImageIO;
import java.awt.*;
import java.io.InputStream;
import java.util.Random;

public class ResourceManager
{
    public Pong game;
    private Image bg;
    private Image pad;
    private Image ball;
    private Font font;

    public ResourceManager(Pong p)
    {
        game = p;
    }

    public void loadResources() {
        bg = initBackground();
        font = initFont(Pong.class.getResourceAsStream("resources/Bebas.ttf"));
        pad = initPad();
        ball = initBall();
    }

    public Image initBackground() {
        Image tmp = null;
        try {
            tmp = ImageIO.read(Pong.class.getResourceAsStream("resources/bg.png"));
        } catch (Exception e) {
            Logger.error("Unable to read background.");
        }
        return (tmp);
    }

    public Font initFont(InputStream is) {
        Font f = null;
        try {
            f = Font.createFont(Font.TRUETYPE_FONT, is);
        } catch (Exception e) {
            Logger.error("Unable to load font.");
        }
        return (f);
    }

    public Image initPad() {
        Image tmp = null;
        try {
            tmp = ImageIO.read(Pong.class.getResourceAsStream("resources/bar.png"));
        } catch (Exception e) {
            Logger.error("Unable to read bar.");
        }
        return (tmp);
    }

    public Image initBall() {
        Image tmp = null;
        try {
            Random r = new Random();
            String ballName = game.getConfigManager().getBalls().get(r.nextInt(4) + 1);

            tmp = ImageIO.read(Pong.class.getResourceAsStream("resources/" + ballName +".png"));
        } catch (Exception e) {
            Logger.error("Unable to read ball.");
            e.printStackTrace();
        }
        return (tmp);
    }

    public Image getBackground()
    {
        return bg;
    }

    public Font getFont() {
        return font;
    }

    public Image getPad() {
        return pad;
    }

    public Image getBall() {
        return ball;
    }
}
