<?php

namespace Src;

require_once 'Methods/NewtonMethod.php';
require_once 'Methods/BissectionMethod.php';
require_once 'Methods/SecantMethod.php';
use Methods\NewtonMethod;
use Methods\BissectionMethod;
use Methods\SecantMethod;

class Torus {

    public $method;

    public function __construct($method, $a0, $a1, $a2, $a3, $a4, $precision)
    {
        switch ($method) {
            case 1:
                $this->method = new BissectionMethod($a0, $a1, $a2, $a3, $a4, $precision);
                break;
            case 2:
                $this->method = new NewtonMethod($a0, $a1, $a2, $a3, $a4, $precision);
                break;
            case 3:
                $this->method = new SecantMethod($a0, $a1, $a2, $a3, $a4, $precision);
                break;
        }
    }

    public function solveEquation() {
        $this->method->solveThat();
    }
}