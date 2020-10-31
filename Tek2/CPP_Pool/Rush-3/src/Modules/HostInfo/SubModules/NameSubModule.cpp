/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** NameSubModule.cpp
*/

#include "NameSubModule.hpp"

HostInfo::NameSubModule::NameSubModule(): IMonitorSubModule("Name")
{
    init();
}

void HostInfo::NameSubModule::refresh()
{
    const std::string cp = "/proc/sys/kernel/hostname";
    std::ifstream file(cp.c_str());
    std::string str;

    if (file) {
        getline(file, str, '\n');
        _value = str;
    } else
        _value = "ERROR";
}


