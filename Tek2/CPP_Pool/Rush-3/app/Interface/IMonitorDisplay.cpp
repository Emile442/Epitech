/*
** EPITECH PROJECT, 2019
** rush_3
** File description:
** Created by Tornike,
*/

#include "IMonitorDisplay.hpp"

IMonitorDisplay::~IMonitorDisplay()
= default;

IMonitorDisplay::IMonitorDisplay(int xsize, int ysize, const std::string &name)
    : Xsize(xsize), Ysize(ysize), Name(name)
{
}

int IMonitorDisplay::getXsize() const
{
    return Xsize;
}

void IMonitorDisplay::setXsize(int xsize)
{
    Xsize = xsize;
}

int IMonitorDisplay::getYsize() const
{
    return Ysize;
}

void IMonitorDisplay::setYsize(int ysize)
{
    Ysize = ysize;
}

const std::string &IMonitorDisplay::getName() const
{
    return Name;
}

void IMonitorDisplay::setName(const std::string &name)
{
    Name = name;
}
