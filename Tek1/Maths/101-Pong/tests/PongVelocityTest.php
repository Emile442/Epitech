<?php

set_include_path(dirname('.'));
require_once 'src/Pong.php';
use PHPUnit\Framework\TestCase;
use Src\Pong;


class PongVelocityTest extends TestCase
{
    public function testVelocityX(): void
    {
        $pong = new Pong([1.1, 3, 5], [-7, 9, 2], 4);
        $this->assertEquals(
            $pong->velocity()[0],
            -8.1
        );
    }

    public function testVelocityY(): void
    {
        $pong = new Pong([1.1, 3, 5], [-7, 9, 2], 4);
        $this->assertEquals(
            $pong->velocity()[1],
            6
        );
    }

    public function testVelocityZ(): void
    {
        $pong = new Pong([1.1, 3, 5], [-7, 9, 2], 4);
        $this->assertEquals(
            $pong->velocity()[2],
            -3
        );
    }

    public function testF()
    {
        exec("php 101pong.php 1 3 5 7 9 -2 -1", $got, $exit);
        $this->assertEquals($exit, "84");
    }
}
