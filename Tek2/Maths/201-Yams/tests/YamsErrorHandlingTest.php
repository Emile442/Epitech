<?php

set_include_path(dirname('.'));
require_once 'src/Yams.php';

use PHPUnit\Framework\TestCase;
use Src\Yams;

/**
 * @coversDefaultClass Src\Yams
*/
class YamsErrorHandlingTest extends TestCase
{
    public function testArgumentEveryThingOk()
    {
        $yams = new Yams(0, 0, 0, 0, 0, "yams_6");
        $this->assertEquals(false, $yams->hasError());
    }

    public function testArgumentOutOfRangeOver()
    {
        $yams = new Yams(8, 0, 0, 0, 0, "yams_6");
        $this->assertEquals(true, $yams->hasError());

        $yams = new Yams(0, 8, 0, 0, 0, "yams_6");
        $this->assertEquals(true, $yams->hasError());

        $yams = new Yams(0, 0, 8, 0, 0, "yams_6");
        $this->assertEquals(true, $yams->hasError());

        $yams = new Yams(0, 0, 0, 8, 0, "yams_6");
        $this->assertEquals(true, $yams->hasError());

        $yams = new Yams(0, 0, 0, 0, 8, "yams_6");
        $this->assertEquals(true, $yams->hasError());
    }

    public function testArgumentOutOfRangeLess()
    {
        $yams = new Yams(-1, 0, 0, 0, 0, "yams_6");
        $this->assertEquals(true, $yams->hasError());

        $yams = new Yams(0, -1, 0, 0, 0, "yams_6");
        $this->assertEquals(true, $yams->hasError());

        $yams = new Yams(0, 0, -1, 0, 0, "yams_6");
        $this->assertEquals(true, $yams->hasError());

        $yams = new Yams(0, 0, 0, -1, 0, "yams_6");
        $this->assertEquals(true, $yams->hasError());

        $yams = new Yams(0, 0, 0, 0, -1, "yams_6");
        $this->assertEquals(true, $yams->hasError());
    }

    public function testIncorrectMode()
    {
        $yams = new Yams(0, 0, 0, 0, 0, "jkfj");
        $this->assertEquals(true, $yams->hasError());
        $this->assertEquals(0, $yams->exec());

        $yams = new Yams(0, 0, 0, 0, 0, "jkfj_5");
        $this->assertEquals(true, $yams->hasError());
        $this->assertEquals(0, $yams->exec());

        $yams = new Yams(0, 0, 0, 0, 0, "yams_s");
        $this->assertEquals(true, $yams->hasError());
        $this->assertEquals(0, $yams->exec());

        $yams = new Yams(0, 0, 0, 0, 0, "yams_10");
        $this->assertEquals(true, $yams->hasError());
        $this->assertEquals(0, $yams->exec());

        $yams = new Yams(0, 0, 0, 0, 0, "yams_-1");
        $this->assertEquals(true, $yams->hasError());
        $this->assertEquals(0, $yams->exec());

        $yams = new Yams(0, 0, 0, 0, 0, "full_4");
        $this->assertEquals(true, $yams->hasError());
        $this->assertEquals(0, $yams->exec());

        $yams = new Yams(0, 0, 0, 0, 0, "full_4_4");
        $this->assertEquals(true, $yams->hasError());
        $this->assertEquals(0, $yams->exec());

        $yams = new Yams(0, 0, 0, 0, 0, "full_4_d");
        $this->assertEquals(true, $yams->hasError());
        $this->assertEquals(0, $yams->exec());

        $yams = new Yams(0, 0, 0, 0, 0, "straight_8");
        $this->assertEquals(true, $yams->hasError());
        $this->assertEquals(0, $yams->exec());

        $yams = new Yams(0, 0, 0, 0, 0, "four_8");
        $this->assertEquals(true, $yams->hasError());
        $this->assertEquals(0, $yams->exec());

        $yams = new Yams(0, 0, 0, 0, 0, "three_8");
        $this->assertEquals(true, $yams->hasError());
        $this->assertEquals(0, $yams->exec());

        $yams = new Yams(0, 0, 0, 0, 0, "pair_8");
        $this->assertEquals(true, $yams->hasError());
        $this->assertEquals(0, $yams->exec());
    }

    public function testCorrectMode()
    {
        $yams = new Yams(0, 0, 0, 0, 0, "pair_1");
        $this->assertEquals(false, $yams->hasError());

        $yams = new Yams(0, 0, 0, 0, 0, "four_1");
        $this->assertEquals(false, $yams->hasError());

        $yams = new Yams(0, 0, 0, 0, 0, "three_1");
        $this->assertEquals(false, $yams->hasError());

        $yams = new Yams(0, 0, 0, 0, 0, "full_4_3");
        $this->assertEquals(false, $yams->hasError());

        $yams = new Yams(0, 0, 0, 0, 0, "straight_5");
        $this->assertEquals(false, $yams->hasError());

        $yams = new Yams(0, 0, 0, 0, 0, "yams_2");
        $this->assertEquals(false, $yams->hasError());
    }
}
