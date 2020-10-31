/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** DateTimeModule.cpp
*/

#include "DateTimeModule.hpp"

DateTimeModule::DateTimeModule()
{

}

void DateTimeModule::refresh()
{
    _date.refresh();
    _time.refresh();
}

const std::string &DateTimeModule::getDate() const
{
    return (_date.getValue());
}

const std::string &DateTimeModule::getTime() const
{
    return (_time.getValue());
}
