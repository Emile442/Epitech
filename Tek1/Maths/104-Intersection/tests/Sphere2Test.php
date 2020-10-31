<?php

set_include_path(dirname('.'));
require_once 'src/Intersection.php';
use PHPUnit\Framework\TestCase;
use Src\Intersection;

/**
 * @coversDefaultClass Src\Intersection
 */
class Sphere2Test extends TestCase
{
    /**
     * @covers ::get_parameter
     */
    public function testRadiusLine(): void
    {
        $intersection = new Intersection(1, [4, 0, 3], [0, 0, -2], 4);
        $this->assertEquals(
            $intersection->get_parameter(),
            "Sphere of radius 4"
        );
    }

    /**
     * @covers ::get_right_coord
     */
    public function testPassingCoord(): void
    {
        $intersection = new Intersection(1, [4, 0, 3], [0, 0, -2], 4);
        $this->assertEquals(
            $intersection->get_right_coord(),
            "Line passing through the point (4, 0, 3) and parallel to the vector (0, 0, -2)"
        );
    }

    /**
     * @covers ::calc_sphere
     */
    public function testOutputCoord(): void
    {
        $intersection = new Intersection(1, [4, 0, 3], [0, 0, -2], 4);
        $this->assertEquals(
            $intersection->calc_sphere()[0][0],
            1
        );
        $this->assertEquals(
            $intersection->calc_sphere()[1],
            [4, 0, 0]
        );
    }
}
