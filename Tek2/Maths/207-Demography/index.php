<?php
require_once 'src/EpiProject.php';

use Src\EpiProject;

if ($argc == 2 && ($argv[1] == '-h' || $argv[1] == '--help')) {
    EpiProject::usage();
    exit (0);
}
if ($argc < 2) {
    $given = $argc - 1;
    echo "Missing arguments. 1 | 1 argument needed but {$given} given.\n";
    exit (84);
}

$project = new EpiProject();
$project->process();
$project->display();
