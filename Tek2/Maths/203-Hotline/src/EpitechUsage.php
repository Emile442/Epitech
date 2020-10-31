<?php


namespace Src;

class EpitechUsage
{
    private $name;
    private $vars;

    public function __construct(string $name)
    {
        $this->name = $name;
        $this->vars = [];
    }

    public function display(): void
    {
        echo "USAGE\n";
        // echo "\t./{$this->name} {$this->getArgumentsNameOneLine()}\n\n";
        echo "\t./{$this->name} [n k | d]\n\n";
        echo "DESCRIPTION\n";
        foreach ($this->vars as $item) {
            echo "\t{$item['name']}\t{$item['desc']}\n";
        }
    }

    public function addVars(string $name, string $desc): void
    {
        $tmp = [
            'name' => $name,
            'desc' => $desc
        ];
        array_push($this->vars, $tmp);
    }

    private function getArgumentsNameOneLine(): string
    {
        $arraySize = count($this->vars);
        $tmp = "";
        foreach ($this->vars as $k => $item) {
            $tmp = $tmp . $item['name'];
            if ($k + 1 != $arraySize) {
                $tmp = $tmp . ' ';
            }
        }
        return $tmp;
    }
}
