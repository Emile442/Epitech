/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** DateSubModule.cpp
*/

#include "DateSubModule.hpp"

DateTime::DateSubModule::DateSubModule(): IMonitorSubModule("Date")
{
    init();
}

void DateTime::DateSubModule::refresh()
{
    auto time = std::time(nullptr);
    std::stringstream ss;

    ss << std::put_time(std::localtime(&time), "%d/%m/%Y");
    _value = ss.str();
}
