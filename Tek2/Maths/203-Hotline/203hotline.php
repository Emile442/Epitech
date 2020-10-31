<?php
require_once 'src/Hotline.php';
use Src\Hotline;

if ($argc == 2 && ($argv[1] == '-h' || $argv[1] == '--help')) {
    Hotline::usage();
exit (0);
}
if ($argc != 2 && $argc != 3) {
    $given = $argc - 1;
    echo "Missing arguments. 1 | 2 argument needed but {$given} given.\n";
    exit (84);
}

if ($argc == 3) {
    if (!is_numeric($argv[1]) || !is_numeric($argv[2])) {
        echo "Wrong Arguments";
        exit(84);
    }
    $hotline = new Hotline($argv[1], $argv[2], Hotline::COMPUTATION);
} else {
    if (!is_numeric($argv[1])) {
        echo "Wrong Arguments";
        exit(84);
    }
    $hotline = new Hotline($argv[1], null, Hotline::DURATION);
}

$hotline->display();
