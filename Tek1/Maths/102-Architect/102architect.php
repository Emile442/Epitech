<?php
require 'src/Architect.php';
use src\Architect;

$architect = new Architect();
$matrix = [[1, 0, 0], [0, 1, 0], [0, 0, 1]];
$i = 3;

if (!$architect->checkArgs($argc, $argv))
    exit(84);

while ($argv[$i]) {
    switch ($argv[$i]) {
        case '-t':
            echo "Translation along vector ({$argv[$i + 1]}, {$argv[$i + 2]})\n";
            $matrix_tmp = [[1, 0, 0], [0, 1, 0], [$argv[$i + 1], $argv[$i + 2], 1]];
            $matrix = $architect->fusionMatrice($matrix, $matrix_tmp);
            $i += 3;
            break;
        case '-z':
            echo "Scaling by factors {$argv[$i + 1]} and {$argv[$i + 2]}\n";
            $matrix_tmp = [[$argv[$i + 1], 0, 0], [0, $argv[$i + 2], 0], [0, 0, 1]];
            $matrix = $architect->fusionMatrice($matrix, $matrix_tmp);
            $i += 3;
            break;
        case '-r':
            echo "Rotation by a {$argv[$i + 1]} degree angle\n";
            $matrix_tmp = [[cos($argv[$i + 1] * M_PI / 180), sin($argv[$i + 1] * M_PI / 180), 0], [sin($argv[$i + 1] * M_PI / 180) * (-1), cos($argv[$i + 1] * M_PI / 180), 0], [0, 0, 1]];
            $matrix = $architect->fusionMatrice($matrix, $matrix_tmp);
            $i += 2;
            break;
        case '-s':
            echo "Reflection over an axis with an inclination angle of {$argv[$i + 1]} degrees\n";
            $angle_rad = deg2rad($argv[$i + 1]);
            $matrix_tmp = [[cos($angle_rad * 2), sin($angle_rad * 2), 0], [sin($angle_rad * 2), cos($angle_rad * 2) * (-1), 0], [0, 0, 1]];
            $matrix = $architect->fusionMatrice($matrix, $matrix_tmp);
            $i += 2;
            break;
    }
}

$architect->displayMatrice($matrix);

$x =  $argv[1] * $matrix[0][0] + $argv[2] * $matrix[1][0] + 1 * $matrix[2][0];
$y =  $argv[1] * $matrix[0][1] + $argv[2] * $matrix[1][1] + 1 * $matrix[2][1];

echo "(".$argv[1].", ".$argv[2].") => (".number_format($x, 2).", ".number_format($y, 2).")\n";
