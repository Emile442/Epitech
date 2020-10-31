/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** UsernameSubModule.cpp
*/

#include "UsernameSubModule.hpp"

HostInfo::UsernameSubModule::UsernameSubModule(): IMonitorSubModule("Username")
{
    init();
}

void HostInfo::UsernameSubModule::refresh()
{
    char text[255];
    std::string str;
    FILE *name;
    name = popen("whoami", "r");
    fgets(text, sizeof(text), name);
    _value = text;
    _value = _value.substr(0, _value.size()-1);
    pclose(name);
}
