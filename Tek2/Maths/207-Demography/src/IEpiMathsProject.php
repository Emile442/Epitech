<?php

namespace Src;


interface IEpiMathsProject
{
    public function process(): void;
    public function display(): void;

    public static function usage(): void;
}
