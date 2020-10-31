<?php

namespace Methods;

require_once 'CommonMethod.php';
use Methods\CommonMethod;

class NewtonMethod extends CommonMethod
{


    public function  __construct($a0, $a1, $a2, $a3, $a4, $precision)
    {
        parent::__construct($a0, $a1, $a2, $a3, $a4, $precision);
    }

    public function solveThat()
    {
        $currentPoint = 0.5;
        $whileCount = 1;
        echo "x = 0.5\n";
        $solvedEqua = $this->solveEquation($this->a0, $this->a1, $this->a2, $this->a3, $this->a4, $currentPoint);
        $derivatedX = $this->derivateX($this->a0, $this->a1, $this->a2, $this->a3, $currentPoint);
        if ($derivatedX == 0) {
            echo "Division by 0 !\n";
            exit (84);
        }
        $currentPoint = $currentPoint - ($solvedEqua / $derivatedX);
        while (abs($solvedEqua) > pow(10, -$this->precision) && $whileCount < 100) {
            echo "x = ".round($currentPoint, $this->precision)."\n";
            $solvedEqua = $this->solveEquation($this->a0, $this->a1, $this->a2, $this->a3, $this->a4, $currentPoint);
            $derivatedX = $this->derivateX($this->a0, $this->a1, $this->a2, $this->a3, $currentPoint);
            $currentPoint = $currentPoint - ($solvedEqua / $derivatedX);
            $whileCount++;
        }
    }
}