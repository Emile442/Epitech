package fr.fedocker.pong;

import fr.fedocker.pong.game.ConfigManager;
import fr.fedocker.pong.gui.Window;
import fr.fedocker.pong.utils.Logger;
import fr.fedocker.pong.game.ResourceManager;
import fr.fedocker.pong.utils.Util;

public class Pong {

    public Pong instance;
    public ResourceManager resourceManager;
    public ConfigManager configManager;
    public Window window;

    public Pong() {
        instance = this;
        configManager = new ConfigManager(this);
        configManager.setDefaultConfig();
        resourceManager = new ResourceManager(this);
        resourceManager.loadResources();
        window = new Window(this);
        window.openFrame();
    }

    public static void main(String[] args) {
        Logger.info("UI is starting..");
        Logger.info("------ USER SPECS ------");
        Logger.info("OS: " + Util.getUsedPlatform());
        Logger.info("Java Version: " + System.getProperty("java.version"));
        Logger.info("CPU Cores: " + Runtime.getRuntime().availableProcessors());
        Logger.info("JVM Memory: " + Runtime.getRuntime().totalMemory() / (1024 * 1024) + "MB");
        Logger.info("------ END SPECS ------");
        new Pong();
    }

    public Pong getInstance() {
        return instance;
    }

    public ConfigManager getConfigManager() { return configManager; }

    public ResourceManager getResourceManager()
    {
        return resourceManager;
    }

    public Window getWindow() {
        return window;
    }
}
