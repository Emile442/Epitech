package fr.fedocker.pong.game;

import fr.fedocker.pong.Pong;

import java.util.HashMap;

public class ConfigManager {

    public Pong game;
    private HashMap<String, Boolean> config = new HashMap<>();
    private HashMap<Integer, String> balls = new HashMap<>();

    public ConfigManager(Pong p) {
        game = p;
        addBalls();
    }

    public void setDefaultConfig() {
        config.put("enableAI", true);
        config.put("retroMode", false);
    }

    public boolean getConfigValue(String key)
    {
        return (config.get(key));
    }

    public void setConfigValue(String key, boolean value) {
        if (config.containsKey(key))
            config.replace(key, value);
    }

    public void addBalls() {
        balls.put(1, "baseball");
        balls.put(2, "basketball");
        balls.put(3, "basketball2");
        balls.put(4, "soccer");
        balls.put(5, "tennis");
    }

    public HashMap<Integer, String> getBalls() {
        return balls;
    }
}
