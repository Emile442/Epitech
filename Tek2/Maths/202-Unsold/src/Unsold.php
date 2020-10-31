<?php


namespace Src;

use Couchbase\BooleanFieldSearchQuery;

require 'EpitechUsage.php';

Class Unsold {

    private $a;
    private $b;
    private $jointLaw;
    private $zLaw;
    private $variance;

    public function __construct(int $a, int $b)
    {
        $this->a = $a;
        $this->b = $b;
    }

    // Display Function
    //
    public function show(): void
    {
        $this->separator();
        $this->jointLaw();
        $this->zLaw();
        $this->variance();
    }
    private function jointLaw()
    {
        printf ("\tX=10\tX=20\tX=30\tX=40\tX=50\tY law\n");
        for ($y = 10; $y <= 60; $y += 10) {
            printf("%s", $y == 60 ? "X law" : "Y={$y}");
            for($x = 10; $x <= 50; $x += 10)
                printf("\t%.3f", $this->jointLaw[$x / 10 - 1][$y / 10 - 1]);
            printf("\t%.3f\n", $y == 60 ? 1 : $this->jointLaw[5][$y / 10 - 1]);
        }
        $this->separator();
    }
    private function zLaw()
    {
        printf ("z\t20\t30\t40\t50\t60\t70\t80\t90\t100\n");
        printf ("p(Z=z)");

        for ($i = 0; $i < 9; $i++)
            printf("\t%.3f%s", $this->zLaw[$i], $i == 8 ? "\n" : "");
        $this->separator();
    }
    private function variance()
    {
        printf("expected value of X:\t%.1f\n", $this->variance[0]);
        printf("variance of X:\t\t%.1f\n", $this->variance[1]);

        printf("expected value of Y\t%.1f\n", $this->variance[2]);
        printf("variance of Y:\t\t%.1f\n", $this->variance[3]);

        printf("expected value of Z:\t%.1f\n", $this->variance[0] + $this->variance[2]);
        printf("variance of Z:\t\t%.1f\n", $this->variance[1] + $this->variance[3]);
        $this->separator();
    }

    // Calc Function
    //
    public function calc(): void {
        $this->jointLaw = $this->calcTab();
        $this->zLaw = $this->calcZLaw();
        $this->variance = $this->calcVariance();
    }
    private function calcTab(): array
    {
        $tab = array_fill(0, 6, array_fill(0, 6, 0));
        $total = array_fill(0, 6, 0);
        for ($i = 10; $i <= 60; $i += 10) {
            $total[5] = 0;
            for($j = 10; $j <= 50; $j += 10) {
                if ($i == 60)
                    $tab[$j / 10 - 1][$i / 10 - 1] = $total[$j / 10 - 1];
                else
                    $tab[$j / 10 - 1][$i / 10 - 1] = (($this->a - $j) * ($this->b - $i)) / ((5 * $this->a - 150) * (5 * $this->b - 150));
                $total[$j / 10 - 1] += $tab[$j / 10 - 1][$i / 10 - 1];
                $total[5] += $tab[$j / 10 - 1][$i / 10 - 1];
            }
            $tab[5][$i / 10 - 1] = $total[5];
        }
        return ($tab);
    }
    private function calcZLaw(): array
    {
        $zTab = array_fill(0, 10, 0);
        for($i = 0; $i < 5; $i++) {
            for ($j = 0; $j < 5; $j++) {
                $zTab[$i + $j] += $this->jointLaw[$i][$j];
                $zTab[9] += $this->jointLaw[$i][$j];
            }
        }
        return $zTab;
    }
    private function calcVariance(): array
    {
        $var = array_fill(0, 4, 0);

        for ($i = 0; $i < 5; $i++) {
            $var[0] += ($i + 1) * 10 * $this->jointLaw[$i][5];
            $var[2] += ($i + 1) * 10 * $this->jointLaw[5][$i];
        }

        for ($i = 0; $i < 5; $i++) {
            $var[1] += (($i + 1) * 10 - $var[0]) * (($i + 1) * 10 - $var[0]) * $this->jointLaw[$i][5];
            $var[3] += (($i + 1) * 10 - $var[2]) * (($i + 1) * 10 - $var[2]) * $this->jointLaw[5][$i];
        }

        return $var;
    }

    // Utils
    //
    public static function usage(): void
    {
        $usage = new EpitechUsage('202unsold');
        $usage->addVars('a', 'constant computed from past results');
        $usage->addVars('b', 'constant computed from past results');
        $usage->display();
    }
    public static function hasError($a, $b): bool
    {
        if (!is_numeric($a) || !is_numeric($b))
            return true;
        if ($a < 0 || $b < 0)
            return true;
        return false;
    }
    private function separator(): void
    {
        echo "--------------------------------------------------------------------------------\n";
    }
}
