<?php

namespace Methods;

class CommonMethod
{

    /**
     * @vars coefficients of the equation
     */
    public $a0;
    public $a1;
    public $a2;
    public $a3;
    public $a4;

    /**
     * @var precision of the equation
     */
    public $precision;

    public function __construct($a0, $a1, $a2, $a3, $a4, $precision)
    {
        $this->a0 = $a0;
        $this->a1 = $a1;
        $this->a2 = $a2;
        $this->a3 = $a3;
        $this->a4 = $a4;
        $this->precision = $precision;
    }

    public function derivateX($a0, $a1, $a2, $a3, $x)
    {
        $b0 = (4 * $a0) * pow($x, 3);
        $b1 = (3 * $a1) * pow($x, 2);
        $b2 = (2 * $a2);
        $b3 = ($a3 + $x);
        return ($b0 + $b1 + $b2 + $b3);
    }

    public function solveEquation($a0, $a1, $a2, $a3, $a4, $x)
    {
        $b0 = ($a0 * pow($x, 4));
        $b1 = ($a1 * pow($x, 3));
        $b2 = ($a2 * pow($x, 2));
        $b3 = ($a3 * $x);
        $b4 = $a4;
        return ($b0 + $b1 + $b2 + $b3 + $b4);
    }
}