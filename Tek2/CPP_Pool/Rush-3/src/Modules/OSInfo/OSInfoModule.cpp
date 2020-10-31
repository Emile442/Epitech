/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** OSInfoModule.cpp
*/

#include "OSInfoModule.hpp"

OSInfoModule::OSInfoModule()
{

}

void OSInfoModule::refresh()
{
    _name.refresh();
    _version.refresh();
    _osVersion.refresh();
}

const std::string &OSInfoModule::getName() const
{
    return (_name.getValue());
}

const std::string &OSInfoModule::getVersion() const
{
    return (_version.getValue());
}

const std::string &OSInfoModule::getOsVersion() const
{
    return (_osVersion.getValue());
}
