<?php

namespace Methods;

require_once 'CommonMethod.php';
use Methods\CommonMethod;

class BissectionMethod extends CommonMethod
{

    public function  __construct($a0, $a1, $a2, $a3, $a4, $precision)
    {
        parent::__construct($a0, $a1, $a2, $a3, $a4, $precision);
    }

    public function solveThat()
    {
        $point1 = 0;
        $point2 = 1;
        $whileCount = 1;
        while (($point2 - $point1) > pow(10, -$this->precision) && $whileCount < 100) {
            $currentPoint = ($point1 + $point2) / 2;
            echo "x = " . round($currentPoint, $this->precision)."\n";
            $solvedEquaP1 = $this->solveEquation($this->a0, $this->a1, $this->a2, $this->a3, $this->a4, $point1);
            $solvedEquaCurrent = $this->solveEquation($this->a0, $this->a1, $this->a2, $this->a3, $this->a4, $currentPoint);
            if (($solvedEquaP1 * $solvedEquaCurrent) >= 0)
                $point1 = $currentPoint;
            else
                $point2 = $currentPoint;
            $whileCount++;
        }
    }
}
