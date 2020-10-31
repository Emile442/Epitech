<?php

namespace Src;

class Pong {
    /**
     * @var array
     */
    private $start;
    /**
     * @var array
     */
    private $end;
    /**
     * @var int
     */
    private $time;

    public function __construct(array $start, array $end, int $time)
    {
        if ($time < 0)
            exit(84);
        $this->start = $start;
        $this->end = $end;
        $this->time = $time;
    }

    /**
     * @return array
     */
    public function velocity(): array
    {
        $velocity = [$this->end[0] - $this->start[0],
            $this->end[1] - $this->start[1],
            $this->end[2] - $this->start[2]];

        return ($velocity);
    }

    /**
     * @return array
     */
    public function coor_at_t(): array
    {
        $coord = [$this->end[0] + $this->time * $this->velocity()[0],
            $this->end[1] + $this->time * $this->velocity()[1],
            $this->end[2] + $this->time * $this->velocity()[2]];
        return $coord;
    }

    /**
     * @param int $mode
     * @return float
     */
    public function rt_angle(int $mode): float
    {
        $velocity = $this->velocity();

        if ($this->start[2] == 0 && $this->end[2] == 0)
            return (0);
        if (!$this->reach_b())
            return (-1);
        else if ($this->start[0] == 0 && $this->start[1] == 0 && $this->start[2] == 0 && $this->end[0] == 0 && $this->end[1] == 0 && $this->end[2] == 0)
            return (0);
        $square = sqrt(pow($velocity[0], 2) + pow($velocity[1], 2) + pow($velocity[2], 2));
        $rad = abs(acos($velocity[2]/$square) - M_PI_2);
        return($mode ? rad2deg($rad) : $rad);
    }

    /**
     * @return bool
     */
    private function reach_b(): bool
    {
        $velocity = $this->velocity();

        if ($this->start[0] == $this->end[0] && $this->start[1] == $this->end[1])
            return (true);
        if ($this->start[2] == $this->end[2] && $this->start[2] != 0 && $this->end[2] != 0)
            return (false);
        if ($velocity[2] != 0 && $this->end[0] != 0 && (($this->end[2] * (-1))/$velocity[2]) >= 0)
            return (true);
        return (false);
    }
}
