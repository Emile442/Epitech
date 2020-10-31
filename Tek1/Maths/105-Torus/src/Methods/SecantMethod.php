<?php

namespace Methods;

require_once 'CommonMethod.php';
use Methods\CommonMethod;

class SecantMethod extends CommonMethod
{

    public function  __construct($a0, $a1, $a2, $a3, $a4, $precision)
    {
        parent::__construct($a0, $a1, $a2, $a3, $a4, $precision);
    }

    public function solveThat()
    {
        $point1 = 0;
        $point2 = 1;
        $solvedEquaP1 = $this->solveEquation($this->a0, $this->a1, $this->a2, $this->a3, $this->a4, $point1);
        $solvedEquaP2 = $this->solveEquation($this->a0, $this->a1, $this->a2, $this->a3, $this->a4, $point2);
        $whileCount = 1;
        if ($solvedEquaP1 == $solvedEquaP2) {
            echo "Division by 0 !\n";
            exit (84);
        }
        $point2 = $point1;
        $point1 = $point1 -(($solvedEquaP1 * ($point1 - $point2)) / ($solvedEquaP1 - $solvedEquaP2));
        while (abs($solvedEquaP1) > pow(10, -$this->precision) && $whileCount < 100) {
            $solvedEquaP1 = $this->solveEquation($this->a0, $this->a1, $this->a2, $this->a3, $this->a4, $point1);
            $solvedEquaP2 = $this->solveEquation($this->a0, $this->a1, $this->a2, $this->a3, $this->a4, $point2);
            if ($solvedEquaP1 == $solvedEquaP2) {
                echo "Division by 0 !\n";
                exit (84);
            }
            $point2 = $point1;
            $point1 = $point1 -(($solvedEquaP1 * ($point1 - $point2)) / ($solvedEquaP1 - $solvedEquaP2));
            $whileCount++;
        }
    }
}
