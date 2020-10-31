/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** CpuInfoModule.cpp
*/

#include "CpuInfoModule.hpp"

CpuInfoModule::CpuInfoModule()
{

}

void CpuInfoModule::refresh()
{
    _usage.refresh();
}

const std::vector<CPUUsage> &CpuInfoModule::getUsage() const
{
    return (_usage.getUsage());
}
