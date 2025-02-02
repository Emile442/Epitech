<?php

set_include_path(dirname('.'));
require_once 'src/Yams.php';

use PHPUnit\Framework\TestCase;
use Src\Yams;

/**
 * @coversDefaultClass Src\Yams
 */
class UsageTest extends TestCase {

    public function testUsage()
    {
        $s = "USAGE\n\t./201yams d1 d2 d3 d4 d5 c\n\nDESCRIPTION\n\td1\tvalue of the first die (0 if not thrown)\n\td2\tvalue of the second die (0 if not thrown)\n\td3\tvalue of the third die (0 if not thrown)\n\td4\tvalue of the fourth die (0 if not thrown)\n\td5\tvalue of the fifth die (0 if not thrown)\n\tc\texpected combination\n";

        Yams::usage();
        $this->expectOutputString($s);
    }
}
