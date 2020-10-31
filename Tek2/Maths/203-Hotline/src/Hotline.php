<?php


namespace Src;

require 'EpitechUsage.php';

Class Hotline {

    const COMPUTATION = 1;
    const DURATION = 2;

    private $n;
    private $k;
    private $mode;

    public function __construct(int $n, ?int $k, int $mode)
    {
        $this->n = $n;
        $this->k = $k;
        $this->mode = $mode;
    }

    public function display()
    {
        if ($this->mode == self::COMPUTATION) {
            echo "{$this->k}-combination of a {$this->n} set:\n";
            $res = $this->binCoeff($this->n, $this->k);
            echo rtrim(sprintf('%f',floatval($res)),'0');
        } elseif ($this->mode == self::DURATION) {
            echo "Mode 2";
        } else {
            echo "Wrong mode";
        }
    }

    // Todo rework this part
    private function binCoeff($n, $k) {
        if ($k > $n - $k)
            $k = $n - $k;

        $result = 1;

        for ($i = 0; $i < $k; ++$i) {
            $result *= ($n - $i);
            $result /= ($i + 1);
        }
        return $result;
    }


    // Utils
    //
    public static function usage(): void
    {
        $usage = new EpitechUsage('203hotline');
        $usage->addVars('n', 'n value for the computation of C(n, k)');
        $usage->addVars('k', 'k value for the computation of C(n, k)');
        $usage->addVars('d', 'average duration of calls (in seconds)');
        $usage->display();
    }
}
