<?php


namespace Src;

class EpiUsage
{
    private $name;
    private $vars;
    private $unlimitedArgs;

    public function __construct(string $name)
    {
        $this->name = $name;
        $this->vars = [];
        $this->unlimitedArgs = false;
    }

    public function display(): void
    {
        echo "USAGE\n";
        echo "\t./{$this->name} {$this->getArgumentsNameOneLine()}{$this->getUnlimitedArgsLine()}\n\n";
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
    public function setUnlimitedArgs(bool $unlimitedArgs): void
    {
        $this->unlimitedArgs = $unlimitedArgs;
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
    private function getUnlimitedArgsLine(): string
    {
        return $this->unlimitedArgs ? ' [...]' : '';
    }

}
