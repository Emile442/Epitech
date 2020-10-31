<?php
require_once 'src/Yams.php';
use Src\Yams;

if ($argc == 2 && ($argv[1] == '-h' || $argv[1] == '--help')) {
    Yams::usage();
    exit (0);
}

if ($argc != 7) {
    echo "Missing arguments. 6 arguments needed but " . $argc . " given.\n";
    exit (84);
}

$yams = new Yams($argv[1], $argv[2], $argv[3], $argv[4], $argv[5], $argv[6]);

if ($yams->hasError())
    exit (84);

$yams->exec();


