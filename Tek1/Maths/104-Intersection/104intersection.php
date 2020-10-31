<?php

require 'src/Intersection.php';

use src\Intersection;

$intersection = new Intersection(intval($argv[1]), [intval($argv[2]), intval($argv[3]), intval($argv[4])], [intval($argv[5]), intval($argv[6]), intval($argv[7])], intval($argv[8]));

if (!$intersection->check_args())
    exit(84);

printf("%s\n", $intersection->get_parameter());
printf("%s\n", $intersection->get_right_coord());

if ($intersection->getOpt() == Intersection::SPHERE)
    $intersection->display_coord($intersection->calc_sphere());
if ($intersection->getOpt() == Intersection::CYLINDER)
    $intersection->display_coord($intersection->calc_cynlinder());
if ($intersection->getOpt() == Intersection::CONE)
    $intersection->display_coord($intersection->calc_cone());

