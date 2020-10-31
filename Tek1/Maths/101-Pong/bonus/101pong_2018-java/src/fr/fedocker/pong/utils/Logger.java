package fr.fedocker.pong.utils;

public class Logger
{
    public static void info(String msg)
    {
        System.out.println("[101-pong] " + msg);
    }

    public static void error(String msg)
    {
        System.err.println("[101-pong] " + msg);
    }
}
