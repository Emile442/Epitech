/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** RamInfoModule.cpp
*/

#include "RamInfoModule.hpp"

RamInfoModule::RamInfoModule()
{

}

void RamInfoModule::refresh()
{
    _total.refresh();
    _available.refresh();
}

const std::string &RamInfoModule::getTotal() const
{
    return (_total.getValue());
}

const std::string &RamInfoModule::getAvailable() const
{
    return (_available.getValue());
}
