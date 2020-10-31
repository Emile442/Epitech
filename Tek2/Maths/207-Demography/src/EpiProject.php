<?php

namespace Src;

require 'EpiUsage.php';
require 'IEpiMathsProject.php';

Class EpiProject implements IEpiMathsProject {

    const FILENAME = '207demography_data.csv';

    public function __construct()
    {

    }

    public function process(): void
    {

    }

    public function display(): void
    {
        $this->getCsvFile();
    }

    public static function usage(): void
    {
        $usage = new EpiUsage('207demography');
        $usage->addVars('code', 'country code');
        $usage->setUnlimitedArgs(true);
        $usage->display();
    }

    private function getFilePath(): string
    {
        return getcwd() . '/' . self::FILENAME;
    }

    private function getCsvFile()
    {
        $array = [];

        if (($handle = fopen($this->getFilePath(), "r")) !== FALSE) {
            for ($row = 1; ($data = fgetcsv($handle, 0)) !== FALSE; $row++) {
                echo "Line number [$row]\n";
                echo $data[0] . "\n\n";
                if ($row == 1) {
                    $strArray = explode(';', $data[0]);
                    foreach ($strArray as $index) {
                        echo $index . "";
                    }
                    break;
                }
            }
            fclose($handle);
        }


        var_dump($array);
    }


}
