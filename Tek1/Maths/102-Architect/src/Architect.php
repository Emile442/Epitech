<?php

namespace src;


class Architect
{
    public function checkArgs($argc, $argv) : bool
    {
        $availble_arg = ['-t', '-z', '-r', '-s'];
        $i = 3;
        if (is_null($argv[1]) || is_null($argv[3]))
            return (false);
        if (!isset($argv[1]) || !isset($argv[2]))
            return (false);
        if (!is_numeric($argv[1]) || !is_numeric($argv[2]))
            return (false);
        if ($argv[3] && !in_array($argv[3], $availble_arg))
            return (false);
        while ($argv[$i]) {
            switch ($argv[$i]) {
                case '-t':
                    if (!is_numeric($argv[$i + 1]) || !is_numeric($argv[$i + 2]))
                        return (false);
                    if ($argv[$i + 3] != null && !in_array($argv[$i + 3], $availble_arg))
                        return (false);
                    $i += 3;
                    break;
                case '-z':
                    if (!is_numeric($argv[$i + 1]) || !is_numeric($argv[$i + 2]))
                        return (false);
                    if ($argv[$i + 3] && !in_array($argv[$i + 3], $availble_arg))
                        return (false);
                    $i += 3;
                    break;
                case '-r':
                    if (!is_numeric($argv[$i + 1]))
                        return (false);
                    if ($argv[$i + 2] && !in_array($argv[$i + 2], $availble_arg))
                        return (false);
                    $i += 2;
                    break;
                case '-s':
                    if (!is_numeric($argv[$i + 1]))
                        return (false);
                    if ($argv[$i + 2] && !in_array($argv[$i + 2], $availble_arg))
                        return (false);
                    $i += 2;
                    break;
            }
        }
        return (true);
    }

    public function displayMatrice($matrix)
    {
        echo number_format($matrix[0][0], 2)."   ";
        echo number_format($matrix[1][0], 2)."   ";
        echo number_format($matrix[2][0], 2)."\n";

        echo number_format($matrix[0][1], 2)."   ";
        echo number_format($matrix[1][1], 2)."   ";
        echo number_format($matrix[2][1], 2)."\n";

        echo number_format($matrix[0][2], 2)."   ";
        echo number_format($matrix[1][2], 2)."   ";
        echo number_format($matrix[2][2], 2)."\n";
    }

    public function fusionMatrice($matrix, $matrix_tmp)
    {
        $matrix_result = [[0, 0, 0], [0, 0, 0], [0, 0, 0]];
        for ($i = 0; $i < 3; $i++) {
            for ($j = 0; $j < 3; $j++) {
                for ($k = 0; $k < 3; $k++) {
                    $matrix_result[$i][$j] += $matrix[$i][$k] * $matrix_tmp[$k][$j];
                }
            }
        }
        return ($matrix_result);
    }
}
