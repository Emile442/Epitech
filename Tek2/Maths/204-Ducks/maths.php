<?php
require_once 'src/EpitechUsage.php';

use Src\EpitechUsage;

const REQUIRE_ARGS = 1;

if ($argc == 2 && ($argv[1] == '-h' || $argv[1] == '--help')) {
    $usage = new EpitechUsage('202unsold');
    $usage->addVars('a', 'constant');
    $usage->display();
    exit (0);
}

if ($argc != REQUIRE_ARGS + 1) {
    $given = $argc - 1;
    echo "Missing arguments. " . REQUIRE_ARGS . " arguments needed but {$given} given.\n";
    exit (84);
}

$a = $argv[1];

function has_error($a)
{
    if (!is_numeric($a) || !strpos($a, '.')) return true;
    if (!is_float(floatval($a))) return true;
    if ($a <= 0 || $a > 2.5) return true;
    return false;
}

if (has_error($a)) exit(84);

function prob($a, $t)
{
    return (-$a * exp(-$t) - (4 - 3 * $a) / 2 * exp(-2 * $t) - (2 * $a - 4) / 4 * exp(-4 * $t));
}

function time_to_back($val, $percent)
{
    $time = 0;

    while (prob($val, $time / 60) - prob($val, 0) < $percent / 100)
        $time += 0.1;
    return ($time);
}

function display_time($a, $percent)
{
    $tmp = time_to_back($a, $percent);
    printf("Time after which %d%% of the ducks are back: %dm %d%ds\n", $percent, $tmp/60, $tmp%60/10, $tmp%10);
}

function display_percentage($a, $minutes)
{
    $tmp = (prob($a, $minutes) - prob($a, 0)) * 100;
    printf("Percentage of ducks back after 2 minute: %.1f%%\n", $tmp);
}

printf("Average return time: 0m 50s\n");
printf("Standard deviation: 1.074\n");
display_time($a, 50);
display_time($a, 99);
display_percentage($a, 1);
display_percentage($a, 2);
