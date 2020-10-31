<?php
require_once 'src/Torus.php';

use Src\Torus;

if ($argc == 2 && $argv[1] == '-h') {
    echo "USAGE\n";
    echo "    ./105torus opt a0 a1 a2 a3 a4 n\n\n";
    echo "DESCRIPTION\n";
    echo "    opt       method option:\n";
    echo "                  1 for the bisection method\n";
    echo "                  2 for Newton's method\n";
    echo "                  3 for the secant method\n";
    echo "    a[0-4]    coefficients of the equation\n";
    echo "    n         precision (the application of the polynomial to the solution should\n";
    echo "              be smaller than 10^-n)\n";
    exit (0);
}

if ($argc != 8) {
    echo "Issue with arguments. 7 arguments needed but " . $argc . " given.\n";
    exit (84);
}

if ($argc == 8) {
    if (!is_numeric($argv[1]) || !is_numeric($argv[2]) || !is_numeric($argv[3]) || !is_numeric($argv[4]) ||
        !is_numeric($argv[5]) || !is_numeric($argv[6]) || !is_numeric($argv[7])) {
        echo "One of the arguments is not a number.";
        exit (84);
    }

    if ($argv[1] == 1 || $argv[1] == 2 || $argv[1] == 3) {
        $torus = new Torus($argv[1], $argv[6], $argv[5], $argv[4], $argv[3], $argv[2], $argv[7]);
        $torus->solveEquation();
    }
    else {
        echo "Invalid method choosed. You can only pick: \n\n";
        echo "1: Bissection Method\n";
        echo "2: Newton's Method\n";
        echo "3: Secant Method\n";
        echo "\n";
        exit (84);
    }
}