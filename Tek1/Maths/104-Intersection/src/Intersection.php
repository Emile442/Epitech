<?php

namespace src;

class Intersection
{
    private $opt;
    private $point;
    private $vector;
    private $p;

    const SPHERE    = 1;
    const CYLINDER  = 2;
    const CONE      = 3;

    public function __construct(int $opt, array $point , array $vector, int $p)
    {
        $this->opt = $opt;
        $this->point = $point;
        $this->vector = $vector;
        $this->p = $p;
    }

    public function getOpt(): int
    {
        return $this->opt;
    }

    public function check_args() : bool
    {
        return (true);
    }

    public function get_parameter() : string
    {
        $str = '';

        if ($this->opt == self::SPHERE)
            $str = "Sphere of radius {$this->p}";
        else if ($this->opt == self::CYLINDER)
            $str = "Cylinder of radius {$this->p}";
        else if ($this->opt == self::CONE)
            $str = "Cone with a {$this->p} degree angle";
        return ($str);
    }

    public function get_right_coord() : string
    {
        return ("Line passing through the point ({$this->point[0]}, {$this->point[1]}, {$this->point[2]}) and parallel to the vector ({$this->vector[0]}, {$this->vector[1]}, {$this->vector[2]})");
    }

    public function display_coord($coord) : void
    {
        if (!$coord[0][0])
            printf("No intersection point.\n");
        elseif ($coord[0][0] == 1)
            printf("1 intersection point:\n(%.3f, %.3f, %.3f)\n", $coord[1][0], $coord[1][1], $coord[1][2]);
        elseif ($coord[0][0] == 2)
            printf("2 intersection points:\n(%.3f, %.3f, %.3f)\n(%.3f, %.3f, %.3f)\n", $coord[1][0], $coord[1][1], $coord[1][2], $coord[2][0], $coord[2][1], $coord[2][2]);
        elseif ($coord[0][0] == 3)
            printf("There is an infinite number of intersection points.\n");
    }

    private function calc_coord($a, $b, $c) : array
    {
        $delta = $b * $b - 4 * $a * $c;
        /*if ($b == 0)
            return ([[3]]);*/
        if ($delta == 0) {
            $x = -$b / (2 * $a);
            return ([
                [1],
                [
                    number_format($x * $this->vector[0] + $this->point[0], 3),
                    number_format($x * $this->vector[1] + $this->point[1], 3),
                    number_format($x * $this->vector[2] + $this->point[2], 3)
                ]
            ]);
        }
        if ($delta > 0) {
            $x1 = (-$b + sqrt($delta)) / (2 * $a);
            $x2 = (-$b - sqrt($delta)) / (2 * $a);
            return ([
                [2],
                [
                    number_format($this->point[0] + $x1 * $this->vector[0],3),
                    number_format($this->point[1] + $x1 * $this->vector[1],3),
                    number_format($this->point[2] + $x1 * $this->vector[2],3)
                ],
                [
                    number_format($this->point[0] + $x2 * $this->vector[0], 3),
                    number_format($this->point[1] + $x2 * $this->vector[1], 3),
                    number_format($this->point[2] + $x2 * $this->vector[2], 3)
                ]
            ]);
        }
        return ([[0]]);
    }

    public function calc_sphere() : array
    {
        $a = pow($this->vector[0], 2) + pow($this->vector[1], 2) + pow($this->vector[2], 2);
        $b = 2 * (($this->point[0] * $this->vector[0]) + ($this->point[2] * $this->vector[1]) + ($this->point[2] * $this->vector[2]));
        $c = (pow($this->point[0], 2) + pow($this->point[1], 2) + pow($this->point[2], 2)) - pow($this->p, 2);

        return ($this->calc_coord($a, $b, $c));
    }

    public function calc_cynlinder() : array
    {
        $a = pow($this->vector[0], 2) + pow($this->vector[1], 2);
        $b = 2 * (($this->point[0] * $this->vector[0]) + ($this->point[0] * $this->vector[1]));
        $c = (pow($this->point[0], 2) + pow($this->point[1], 2)) - pow($this->p, 2);

        return ($this->calc_coord($a, $b, $c));
    }

    public function calc_cone() : array
    {
        $p_rad = pow(tan(deg2rad($this->p)), 2);
        $a = pow($this->vector[0], 2) + pow($this->vector[1], 2) - pow($this->vector[2], 2) * $p_rad;
        $b = 2 * ($this->vector[0] * $this->point[0] + $this->vector[1] * $this->point[1] - $this->vector[2] * $this->point[2] * $p_rad);
        $c = pow($this->point[0], 2) + pow($this->point[1], 2) - pow($this->point[2], 2) * $p_rad;

        return ($this->calc_coord($a, $b, $c));
    }

}
