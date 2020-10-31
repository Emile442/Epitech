<?php

set_include_path(dirname('.'));
require_once 'src/Pong.php';
use PHPUnit\Framework\TestCase;
use Src\Pong;

class PongRtAngleTest extends TestCase
{
    public function testRtAngle(): void
    {
        $pong = new Pong([1.1, 3, 5], [-7, 9, 2], 4);
        $this->assertEquals(
            round($pong->rt_angle(1), 2),
            16.57
        );
    }

    public function testRtAngle00(): void
    {
        $pong = new Pong([1, 1, 1], [2, 2, 1], 1);
        $this->assertEquals(
            round($pong->rt_angle(1), 2),
            -1
        );
    }

    public function testRtAngle0(): void
    {
        $pong = new Pong([2, 4, 3], [5, 1, 3], 6);
        $this->assertEquals(
            round($pong->rt_angle(1), 2),
            -1
        );
    }

    public function testRtAngle90(): void
    {
        $pong = new Pong([0, 0, 3], [0, 0, 4], 6);
        $this->assertEquals(
            round($pong->rt_angle(1), 2),
            90
        );
    }

    public function testRtAngleInvalid(): void
    {
        $pong = new Pong([1, 3, 5], [7, 9, -2], 4);
        $this->assertEquals(
            round($pong->rt_angle(1), 2),
            -1
        );
    }

    public function testRtAngleZero(): void
    {
        $pong = new Pong([0, 0, 0], [0, 0, 0], 0);
        $this->assertEquals(
            round($pong->rt_angle(1), 2),
            0
        );
    }
}
