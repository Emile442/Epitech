<?php

set_include_path(dirname('.'));
require_once 'src/Yams.php';

use PHPUnit\Framework\TestCase;
use Src\Yams;

/**
 * @coversDefaultClass Src\Yams
 */
class ModeTest extends TestCase
{
    public function testPair()
    {
        $yams = new Yams(4, 5, 4 ,5, 5, "pair_4");
        $this->assertEquals(false, $yams->hasError());

        $this->assertEquals(100, $yams->exec());
        $this->expectOutputString("Chances to get a 4 pair: 100.00%\n");
    }

    public function testThree()
    {
        $yams = new Yams(3, 5, 5, 6, 2, "three_4");
        $this->assertEquals(false, $yams->hasError());

        $this->assertEquals(3.55, $yams->exec());
        $this->expectOutputString("Chances to get a 4 three-of-a-kind: 3.55%\n");
    }

    public function testFour()
    {
        $yams = new Yams(1, 2, 3, 4, 5, "four_4");
        $this->assertEquals(false, $yams->hasError());

        $this->assertEquals(1.62, $yams->exec());
        $this->expectOutputString("Chances to get a 4 four-of-a-kind: 1.62%\n");
    }

    public function testFull()
    {
        $yams = new Yams(0, 0, 0, 0, 0, "full_2_3");
        $this->assertEquals(false, $yams->hasError());
        $this->assertEquals(0.13, $yams->exec());
        $str1 = "Chances to get a 2 full of 3: 0.13%\n";
        $this->expectOutputString($str1);


        $yams = new Yams(2, 3, 2, 3, 2, "full_2_3");
        $this->assertEquals(false, $yams->hasError());
        $this->assertEquals(100, $yams->exec());
        $str2 = "Chances to get a 2 full of 3: 100.00%\n";
        $this->expectOutputString($str1 . $str2);

        $yams = new Yams(2, 3, 2, 3, 2, "full_3_2");
        $this->assertEquals(false, $yams->hasError());
        $this->assertEquals(166.67, $yams->exec());
        $str3 = "Chances to get a 3 full of 2: 166.67%\n";
        $this->expectOutputString($str1 . $str2 . $str3);

        $yams = new Yams(2, 3, 3, 3, 3, "full_3_2");
        $this->assertEquals(false, $yams->hasError());
        $this->assertEquals(166.67, $yams->exec());
        $str4 = "Chances to get a 3 full of 2: 166.67%\n";
        $this->expectOutputString($str1 . $str2 . $str3 . $str4);
    }

    public function testStraight()
    {
        $yams = new Yams(2, 2, 5, 4, 6, "straight_6");
        $this->assertEquals(false, $yams->hasError());

        $this->assertEquals(16.67, $yams->exec());
        $this->expectOutputString("Chances to get a 6 straight: 16.67%\n");
    }

    public function testYams()
    {
        $yams = new Yams(0, 0, 0, 0, 0, "yams_4");
        $this->assertEquals(false, $yams->hasError());

        $this->assertEquals(0.01, $yams->exec());
        $this->expectOutputString("Chances to get a 4 yams: 0.01%\n");
    }

}
