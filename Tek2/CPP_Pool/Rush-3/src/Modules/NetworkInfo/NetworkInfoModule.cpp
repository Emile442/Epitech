/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** NetworkInfoModule.cpp
*/

#include "NetworkInfoModule.hpp"

NetworkInfoModule::NetworkInfoModule()
{

}

void NetworkInfoModule::refresh()
{
    _up.refresh();
    _down.refresh();
}

const std::string &NetworkInfoModule::getUp()
{
    return (_up.getValue());
}

const std::string &NetworkInfoModule::getDown()
{
    return (_down.getValue());
}
