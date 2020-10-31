<?php
require_once 'src/Pong.php';
use Src\Pong;

if ($argc == 2 && $argv[1] == '-h') {
    echo "USAGE\n";
    echo "       ./101pong x0 y0 z0 x1 y1 z1 n\n";
    echo "DESCRIPTION\n";
    echo "             x0 ball abscissa at time t - 1\n";
    echo "             y0 ball ordinate at time t - 1\n";
    echo "             z0 ball abscissa at time t - 1\n";
    echo "             x1 ball abscissa at time t\n";
    echo "             y0 ball abscissa at time t - 1\n";
    echo "             z0 ball abscissa at time t - 1\n";
    echo "             n time shift (greater than or equal to zero, integer)\n";
    exit (0);
}
if ($argc != 8) {
    echo "Missing arguments. 7 arguments needed but " . $argc . " given.\n";
    exit (84);
}

if (!is_numeric($argv[7]) || strpos($argv[7], '.'))
{
    exit (84);
}

$start = [floatval($argv[1]), floatval($argv[2]), floatval($argv[3])];
$end = [floatval($argv[4]), floatval($argv[5]), floatval($argv[6])];
$time = intval($argv[7]);

if ($time < 0)
    exit (84);

$pong = new Pong($start, $end, $time);

$velocity = $pong->velocity();
$coord = $pong->coor_at_t();
$angle = $pong->rt_angle(1);

echo "The velocity vector of the ball is:\n";
echo "(" .
    number_format($velocity[0], 2) . ', ' .
    number_format($velocity[1], 2) . ', ' .
    number_format($velocity[2], 2) .
    ")\n";

echo "At time t + {$time}, ball coordinates will be:\n";
echo "(" .
    number_format($coord[0], 2) . ', ' .
    number_format($coord[1], 2) . ', ' .
    number_format($coord[2], 2) .
    ")\n";

if ($angle != -1) {
    echo "The incidence angle is: \n";
    echo number_format($angle, 2) . " degrees\n";
} else {
    echo "The ball won't reach the bat.\n";
}
