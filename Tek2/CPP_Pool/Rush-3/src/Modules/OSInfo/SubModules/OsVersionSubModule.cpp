/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** OsVersionSubModule.cpp
*/

#include "OsVersionSubModule.hpp"

OSInfo::OsVersionSubModule::OsVersionSubModule(): IMonitorSubModule("OsVersion")
{
    init();
}

void OSInfo::OsVersionSubModule::refresh()
{
    const std::string cp = "/etc/os-release";
    std::ifstream file(cp.c_str());
    std::string str;

    if (file) {
        getline(file, str);
        getline(file, str);
        str.erase (0,9);
        str.pop_back();
        _value = str;
    } else
        _value = "Bad file!";
}

