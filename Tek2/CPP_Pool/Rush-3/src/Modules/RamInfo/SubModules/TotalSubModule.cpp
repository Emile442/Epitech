/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** TotalSubModule.cpp
*/

#include "TotalSubModule.hpp"

RamInfo::TotalSubModule::TotalSubModule(): IMonitorSubModule("Total")
{
    init();
}

void RamInfo::TotalSubModule::refresh()
{
    std::ifstream file("/proc/meminfo");
    std::string str;

    if (file) {
        getline(file, str, '\n');
        str.erase (0,17);
        str = str.substr(0, str.size()-3);
        _value = str;
    } else
        _value = "ERROR";
}
