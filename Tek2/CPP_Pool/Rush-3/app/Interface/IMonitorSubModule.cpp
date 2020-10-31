/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** IMonitorSubModule.cpp
*/

#include "IMonitorSubModule.hpp"

IMonitorSubModule::IMonitorSubModule(const std::string &name) : _name(name)
{

}

IMonitorSubModule::~IMonitorSubModule()
{

}

void IMonitorSubModule::init()
{
    refresh();
}

const std::string &IMonitorSubModule::getName() const
{
    return (_name);
}

const std::string &IMonitorSubModule::getValue() const
{
    return (_value);
}