<?php

set_include_path(dirname('.'));
require_once 'src/Pong.php';
use PHPUnit\Framework\TestCase;
use Src\Pong;


class PongValidationTest extends TestCase
{

    public function testNegativeTime(): void
    {
        exec("php 101pong.php 1 3 5 7 9 -2 -1", $got, $exit);
        $this->assertEquals($exit, "84");
    }
}
