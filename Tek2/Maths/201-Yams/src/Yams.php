<?php

namespace Src;

Class Yams {

    private $mode;
    private $modeParams;
    private $dices;

    public function __construct(int $d1, int $d2, int $d3, int $d4, int $d5, string $mode)
    {
        $this->dices = [$d1, $d2, $d3, $d4, $d5];
        $this->mode = $mode;
        $this->modeParams = [0 => NULL, 1 => NULL];
    }

    public static function usage()
    {
        echo "USAGE\n";
        echo "\t./201yams d1 d2 d3 d4 d5 c\n\n";
        echo "DESCRIPTION\n";
        echo "\td1\tvalue of the first die (0 if not thrown)\n";
        echo "\td2\tvalue of the second die (0 if not thrown)\n";
        echo "\td3\tvalue of the third die (0 if not thrown)\n";
        echo "\td4\tvalue of the fourth die (0 if not thrown)\n";
        echo "\td5\tvalue of the fifth die (0 if not thrown)\n";
        echo "\tc\texpected combination\n";
    }

    public function hasError() : bool
    {
        foreach ($this->dices as $dice)
            if (!$this->checkDice($dice))
                return (true);
        if (!$this->checkMode($this->mode))
            return (true);
        return (false);
    }

    public function exec() : float
    {
        if ($this->mode == "yams")
            return $this->yams();
        if ($this->mode == "four")
            return $this->four();
        if ($this->mode == "straight")
            return $this->straight();
        if ($this->mode == "full")
            return $this->full();
        if ($this->mode == "pair")
            return $this->pair();
        if ($this->mode == "three")
            return $this->three();
        return (0);
    }


    /* MODE */
    private function three() : float
    {
        $proba = $this->calculProbaBase(3);

        printf("Chances to get a %d three-of-a-kind: %.2f%%\n", $this->modeParams[0], $proba);
        return (round($proba, 2));
    }

    private function four() : float
    {
        $proba = $this->calculProbaBase(4);

        printf("Chances to get a %d four-of-a-kind: %.2f%%\n", $this->modeParams[0], $proba);
        return (round($proba, 2));
    }

    private function yams() : float
    {
        $proba = $this->calculProbaBase(5);

        printf("Chances to get a %d yams: %.2f%%\n", $this->modeParams[0], $proba);
        return (round($proba, 2));
    }

    private function pair() : float
    {
        $proba = $this->calculProbaBase(2);

        printf("Chances to get a %d pair: %.2f%%\n", $this->modeParams[0], $proba);
        return (round($proba, 2));
    }

    private function straight() : float
    {
        $n = 5;

        for ($i = 0, $j = 0; isset($this->dices[$i]); $i++)
            for (;$i > $j; $j++)
                if ($this->dices[$i] == $this->dices[$j])
                    $this->dices[$j] = 0;

        for ($i = 0; isset($this->dices[$i]); $i++)
            if ($this->dices[$i] < $this->modeParams[0] - 5 + 1 || $this->dices[$i] > $this->modeParams[0])
                $n--;

        $proba = ($this->fact(5 - $n) / pow( 6, 5 - $n)) * 100.00;

        printf("Chances to get a %d straight: %.2f%%\n", $this->modeParams[0], $proba);
        return (round($proba, 2));
    }

    private function full() : float
    {
        $n1 = 5;
        $n2 = 5;

        for ($i = 0; isset($this->dices[$i]); $i++) {
            if ($this->dices[$i] != $this->modeParams[0])
                $n1--;
            if ($this->dices[$i] != $this->modeParams[1])
                $n2--;
        }

        if ($n1 == 3 && $n2 == 2)
            $proba = 100;
        else {
            if ($n1 > 3)
                $n1 = 3;
            if ($n2 > 2)
                $n2 = 2;
            $pair = $this->fact(3 - $n1) / ($this->fact(3 - $n1) * $this->fact(0));
            $three = $this->fact(2 - $n2) / ($this->fact(2 - $n2) * $this->fact(0));

            $proba = (($pair * $three) / pow(6, 5 - $n1 - $n2)) * 1000;
        }

        printf("Chances to get a %d full of %d: %.2f%%\n", $this->modeParams[0], $this->modeParams[1], $proba);
        return (round($proba, 2));
    }


    /* MATHS UTILS */
    private function fact($nbr)
    {
        return ($nbr == 0 ? 1 : $nbr * $this->fact($nbr - 1));
    }

    private function binomiale($base, $nbr)
    {
        $cnp = $this->fact($nbr) / ($this->fact($base) * $this->fact($nbr - $base));
        $rt = $cnp * pow(1 / 6, $base) * pow( 5 / 6, $nbr - $base);
        $rt *= 100;
        return ($rt);
    }

    private function calculProbaBase($base)
    {
        $n = 5;

        for ($i = 0; isset($this->dices[$i]); $i++)
            if ($this->dices[$i] != $this->modeParams[0])
                $n--;

        $proba = 0;
        for ($i = $base - $n; $i != 5 - $n + 1; $i++)
            $proba += $this->binomiale($i, 5 - $n);

        return ($proba);
    }


    /* ERROR HANDLING */
    private function checkDice($nbr) : bool {
        return (!(!is_numeric($nbr) || ($nbr < 0 || $nbr > 6)));
    }

    /**
     * Error handling of mode
     * @param $str
     * @return bool
     *
     * 1/ pair_A
     * 2/ three_A
     * 3/ four_A
     * 4/ full_A_B (B -> checkDice()) (A != B)
     * 5/ straight_A
     * 6/ yams_A
     */
    private function checkMode($str) : bool {
        $position = strpos($str, '_');
        if (!$position)
            return (false);

        if (strncmp($str, "pair", $position - 1) == 0 && strlen($str) == $position + 2) {
            if (!$this->checkDice($this->mode[$position + 1]))
                return (false);
            $this->setModeParams($this->mode[$position + 1]);
            $this->setMode("pair");
            return (true);
        }

        if (strncmp($str, "three", $position - 1) == 0 && strlen($str) == $position + 2) {
            if (!$this->checkDice($this->mode[$position + 1]))
                return (false);
            $this->setModeParams($this->mode[$position + 1]);
            $this->setMode("three");
            return (true);
        }

        if (strncmp($str, "four", $position - 1) == 0 && strlen($str) == $position + 2) {
            if (!$this->checkDice($this->mode[$position + 1]))
                return (false);
            $this->setModeParams($this->mode[$position + 1]);
            $this->setMode("four");
            return (true);
        }

        if (strncmp($str, "full", $position - 1) == 0 && strlen($str) == $position + 4) {
            if (!$this->checkDice($this->mode[$position + 1]) || !$this->checkDice($this->mode[$position + 3]))
                return (false);
            if ($this->mode[$position + 1] == $this->mode[$position + 3])
                return (false);
            $this->setModeParams($this->mode[$position + 1], $this->mode[$position + 3]);
            $this->setMode("full");
            return (true);
        }

        if (strncmp($str, "straight", $position - 1) == 0 && strlen($str) == $position + 2) {
            if (!$this->checkDice($this->mode[$position + 1]))
                return (false);
            $this->setModeParams($this->mode[$position + 1]);
            $this->setMode("straight");
            return (true);
        }

        if (strncmp($str, "yams", $position - 1) == 0 && strlen($str) == $position + 2) {
            if (!$this->checkDice($this->mode[$position + 1]))
                return (false);
            $this->setModeParams($this->mode[$position + 1]);
            $this->setMode("yams");
            return (true);
        }

        return (false);
    }

    private function setMode(string $mode)
    {
        $this->mode = $mode;
    }

    private function setModeParams(int $a, int $b = NULL)
    {
        $this->modeParams = [0 => strval($a), 1 => strval($b)];
    }

}
