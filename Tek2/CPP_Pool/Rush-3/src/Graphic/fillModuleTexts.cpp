/*
** EPITECH PROJECT, 2019
** MESTESTS
** File description:
** Created by Tornike,
*/

#include "../../app/Class/GraphicMonitorDisplay.hpp"

void GraphicMonitorDisplay::initDateText(DateTimeModule &_date)
{
    std::string dateRes = "DATE: " + _date.getDate();
    std::string timeRes = "TIME: " + _date.getTime();

    textModules[0].setString(dateRes);
}

void GraphicMonitorDisplay::initHostInfo(HostInfoModule &_host)
{
    std::string hostRes = "HOST: " + _host.getName();
    std::string userRes = "USERNAME: " + _host.getUsername();

    textModules[1].setString(hostRes);
}

void GraphicMonitorDisplay::initNetworkInfo(NetworkInfoModule &_network)
{
    std::string upRes = "UP: " + _network.getUp();
    std::string downRes = "DOWN: " + _network.getDown();

    textModules[2].setString(upRes);
}

void GraphicMonitorDisplay::initOsInfo(OSInfoModule &_os)
{
    std::string nameRes = "NAME: " + _os.getName();
    std::string versionRes = "VERSION: " + _os.getVersion();
    std::string osVersionRes = "OS VERSION: " + _os.getOsVersion();

    textModules[3].setString(nameRes);
}