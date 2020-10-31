package fr.fedocker.pong.math;

import java.lang.Math;

public class MathUtil {

    public double[] start;
    public double[] end;
    public int time;

    public MathUtil(double[] s, double [] e, int t) {
        start = s;
        end = e;
        time = t;
    }

    public double [] getVelocity()
    {
        double[] velocity = {end[0] - start[0], end[1] - start[1], end[2] - start[2]};
        return (velocity);
    }

    public double[] getCoords()
    {
        double[] coords = {end[0] + time * getVelocity()[0], end[1] + time * getVelocity()[1], end[2] + time * getVelocity()[2]};
        return coords;
    }

    public double getAngle(boolean mode)
    {
        if(!reachBat())
            return (-1);
        double square = Math.sqrt(Math.pow(getVelocity()[0], 2) + Math.pow(getVelocity()[1], 2) + Math.pow(getVelocity()[2], 2));
        double rad = Math.abs(Math.acos(getVelocity()[2] / square) - (Math.PI / 2));
        return (mode ? Math.toDegrees(rad) : rad);
    }

    public boolean reachBat()
    {
        if (start[0] == 0 && start[1] == 0 && start[2] == 0 && end[0] == 0 && end[1] == 0 && end[2] == 0)
            return (false);
        if (start[0] == end[0] && start[1] == end[1])
            return (true);
        if (getVelocity()[2] != 0 && end[0] != 0 && ((end[2] * (-1)) / getVelocity()[2]) >= 0)
            return (true);
        return (false);
    }
}
