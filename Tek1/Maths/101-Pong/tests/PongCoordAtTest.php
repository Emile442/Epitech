<?php

set_include_path(dirname('.'));
require_once 'src/Pong.php';
use PHPUnit\Framework\TestCase;
use Src\Pong;

/**
 * @coversDefaultClass Src\Pong
 */
class PongCoordAtTest extends TestCase
{
    /**
     * @covers ::coor_at_t
     */
    public function testCoorAtX(): void
    {
        $pong = new Pong([1.1, 3, 5], [-7, 9, 2], 4);
        $this->assertEquals(
            $pong->coor_at_t()[0],
            -39.4
        );
    }

    /**
     * @covers ::coor_at_t
     */
    public function testCoorAtY(): void
    {
        $pong = new Pong([1.1, 3, 5], [-7, 9, 2], 4);
        $this->assertEquals(
            $pong->coor_at_t()[1],
            33
        );
    }

    /**
     * @covers ::coor_at_t
     */
    public function testCoorAtZ(): void
    {
        $pong = new Pong([1.1, 3, 5], [-7, 9, 2], 4);
        $this->assertEquals(
            $pong->coor_at_t()[2],
            -10
        );
    }
}
