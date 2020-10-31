<?php
require_once 'src/Unsold.php';
use Src\Unsold;

if ($argc == 2 && ($argv[1] == '-h' || $argv[1] == '--help')) {
    Unsold::usage();
    exit (0);
}
if ($argc != 3) {
    $given = $argc - 1;
    echo "Missing arguments. 2 arguments needed but {$given} given.\n";
    exit (84);
}
if (Unsold::hasError($argv[1], $argv[2]))
    exit(84);

$unsold = new Unsold($argv[1], $argv[2]);

$unsold->calc();
$unsold->show();
