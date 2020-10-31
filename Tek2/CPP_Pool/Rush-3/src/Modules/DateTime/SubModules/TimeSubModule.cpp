/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TimeSubModule.cpp
*/

#include "TimeSubModule.hpp"

DateTime::TimeSubModule::TimeSubModule(): IMonitorSubModule("Time")
{
    init();
}

void DateTime::TimeSubModule::refresh()
{
    auto time = std::time(nullptr);
    std::stringstream ss;

    ss << std::put_time(std::localtime(&time), "%H:%M");
    _value = ss.str();
}
