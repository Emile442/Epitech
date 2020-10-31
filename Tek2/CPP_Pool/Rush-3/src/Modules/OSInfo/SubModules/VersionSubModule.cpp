/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** VersionSubModule.cpp
*/

#include "VersionSubModule.hpp"

OSInfo::VersionSubModule::VersionSubModule(): IMonitorSubModule("Version")
{
    init();
}

void OSInfo::VersionSubModule::refresh()
{
    const std::string cp = "/proc/version";
    std::ifstream file(cp.c_str());
    std::string str;

    if (file) {
        getline(file, str, '(');
        str.erase (0,14);
        _value = str;
    } else
        _value = "ERROR";
}

