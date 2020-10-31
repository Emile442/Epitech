/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** OSInfoModule.cpp
*/

#include "HostInfoModule.hpp"

HostInfoModule::HostInfoModule()
{

}

void HostInfoModule::refresh()
{
    _name.refresh();
    _username.refresh();
}

const std::string &HostInfoModule::getName() const
{
    return (_name.getValue());
}

const std::string &HostInfoModule::getUsername() const
{
    return (_username.getValue());
}
