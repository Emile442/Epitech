/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** AvailableSubModule.cpp
*/

#include "AvailableSubModule.hpp"

RamInfo::AvailableSubModule::AvailableSubModule(): IMonitorSubModule("Available")
{
    init();
}

void RamInfo::AvailableSubModule::refresh()
{
    std::ifstream fileStat("/proc/meminfo");
    const std::string title("MemAvailable:");
    std::string str;

    while(std::getline(fileStat, str)) {
        if (!str.compare(0, title.size(), title)) {
            str.erase (0,17);
            str = str.substr(0, str.size()-3);
            _value = str;
        }
    }
}

