/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** NameSubModule.cpp
*/

#include "NameSubModule.hpp"

OSInfo::NameSubModule::NameSubModule(): IMonitorSubModule("Name")
{
    init();
}

void OSInfo::NameSubModule::refresh()
{
    const std::string cp = "/etc/os-release";
    std::ifstream file(cp.c_str());
    std::string str;

    if (file) {
        getline(file, str, '\n');
        str.erase (0,5);
        _value = str;
    } else
        _value = "ERROR";
}


