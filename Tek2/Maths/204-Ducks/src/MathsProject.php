<?php


namespace Src;

require 'EpitechUsage.php';

Class MathsProject {

    private $a;

    public function __construct(int $a)
    {
        $this->a = $a;
    }

    // Utils
    //
    public static function usage(): void
    {
        $usage = new EpitechUsage('202unsold');
        $usage->addVars('a', 'constant');
        $usage->display();
    }

}
