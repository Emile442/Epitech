package fr.voriondev.utils;

public class Utils {

    public static String[] parseStr(String str)
    {
        str.replace("\r", "");
        str.replace("\n", "");
        return (str.split("\\s+"));
    }
}
