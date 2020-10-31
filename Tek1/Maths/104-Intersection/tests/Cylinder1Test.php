<?php

set_include_path(dirname('.'));
require_once 'src/Intersection.php';
use PHPUnit\Framework\TestCase;
use Src\Intersection;

/**
 * @coversDefaultClass Src\Intersection
 */
class Cylinder1Test extends TestCase
{
    /**
     * @covers ::get_parameter
     */
    public function testRadiusLine(): void
    {
        $intersection = new Intersection(2, [0, 0, 2], [1, 1, 0], 1);
        $this->assertEquals(
            $intersection->get_parameter(),
            "Cylinder of radius 1"
        );
    }

    /**
     * @covers ::get_right_coord
     */
    public function testPassingCoord(): void
    {
        $intersection = new Intersection(2, [0, 0, 2], [1, 1, 0], 1);
        $this->assertEquals(
            $intersection->get_right_coord(),
            "Line passing through the point (0, 0, 2) and parallel to the vector (1, 1, 0)"
        );
    }

    /**
     * @covers ::calc_cynlinder
     */
    public function testOutputCoord(): void
    {
        $intersection = new Intersection(2, [0, 0, 2], [1, 1, 0], 1);
        $this->assertEquals(
            $intersection->calc_cynlinder()[0][0],
            2
        );
        $this->assertEquals(
            $intersection->calc_cynlinder()[1],
            [0.707, 0.707, 2]
        );
        $this->assertEquals(
            $intersection->calc_cynlinder()[2],
            [-0.707, -0.707, 2]
        );
    }
}
