package fr.fedocker.pong.utils;

public class Util {
    public static OS getPlatform()
    {
        String osName = System.getProperty("os.name").toLowerCase();

        if (osName.contains("win"))
            return OS.windows;
        if (osName.contains("mac"))
            return OS.macos;
        if (osName.contains("solaris"))
            return OS.solaris;
        if (osName.contains("sunos"))
            return OS.solaris;
        if (osName.contains("linux"))
            return OS.linux;
        if (osName.contains("unix"))
            return OS.linux;
        return OS.unknown;
    }

    public static enum OS
    {
        linux,  solaris,  windows,  macos,  unknown;
    }

    public static String getUsedPlatform()
    {
        String osName = System.getProperty("os.name").toLowerCase();

        if (osName.contains("win"))
            return "Windows";
        if (osName.contains("mac"))
            return "OS X";
        if (osName.contains("solaris"))
            return "Solaris";
        if (osName.contains("sunos"))
            return "Solaris";
        if (osName.contains("linux"))
            return "Linux";
        if (osName.contains("unix"))
            return "Linux";
        return "Unknown operating system.";
    }
}
