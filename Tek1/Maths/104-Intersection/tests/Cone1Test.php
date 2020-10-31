<?php

set_include_path(dirname('.'));
require_once 'src/Intersection.php';
use PHPUnit\Framework\TestCase;
use Src\Intersection;

/**
 * @coversDefaultClass Src\Intersection
 */
class Cone1Test extends TestCase
{
    /**
     * @covers ::get_parameter
     */
    public function testRadiusLine(): void
    {
        $intersection = new Intersection(3, [-1, -1, -1], [1, 1, 5], 30);
        $this->assertEquals(
            $intersection->get_parameter(),
            "Cone with a 30 degree angle"
        );
    }

    /**
     * @covers ::get_right_coord
     */
    public function testPassingCoord(): void
    {
        $intersection = new Intersection(3, [-1, -1, -1], [1, 1, 5], 30);
        $this->assertEquals(
            $intersection->get_right_coord(),
            "Line passing through the point (-1, -1, -1) and parallel to the vector (1, 1, 5)"
        );
    }

    /**
     * @covers ::calc_cone
     */
    public function testOutputCoord(): void
    {
        $intersection = new Intersection(3, [-1, -1, -1], [1, 1, 5], 30);
        $this->assertEquals(
            $intersection->calc_cone()[0][0],
            2
        );
        $this->assertEquals(
            $intersection->calc_cone()[1],
            [-1.568, -1.568, -3.842]
        );
        $this->assertEquals(
            $intersection->calc_cone()[2],
            [-0.537, -0.537, 1.315]
        );
    }
}
