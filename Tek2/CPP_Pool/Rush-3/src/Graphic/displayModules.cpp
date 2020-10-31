/*
** EPITECH PROJECT, 2019
** MESTESTS
** File description:
** Created by Tornike,
*/

#include "../../app/Class/GraphicMonitorDisplay.hpp"

void displayDate(DateTimeModule &_date, sf::RenderWindow &_window, sf::Text &_text, sf::RectangleShape &_rect)
{
    _date.refresh();
    std::string res = "Date: " + _date.getDate() + "\nTime: " + _date.getTime();

    _text.setString(res);
    _text.setPosition(_rect.getPosition());
    _window.draw(_text);
}

void displayHost(HostInfoModule &_host, sf::RenderWindow &_window, sf::Text &_text, sf::RectangleShape &_rect)
{
    _host.refresh();
    std::string res = "Host: " + _host.getName() + "\nUsername: " + _host.getUsername();

    _text.setString(res);
    _text.setPosition(_rect.getPosition());
    _window.draw(_text);
}

void displayNetwork(NetworkInfoModule &_network, sf::RenderWindow &_window, sf::Text &_text, sf::RectangleShape &_rect)
{
    _network.refresh();
    std::string res = "Up: " + _network.getUp() + "\nDown: " + _network.getDown();

    _text.setString(res);
    _text.setPosition(_rect.getPosition());
    _window.draw(_text);
}

void displayOs(OSInfoModule &_os, sf::RenderWindow &_window, sf::Text &_text, sf::RectangleShape &_rect)
{
    _os.refresh();
    std::string res = "Name: " + _os.getName() + "\nVersion: " + _os.getVersion() + "\nOS Version: " + _os.getOsVersion();

    _text.setString(res);
    _text.setPosition(_rect.getPosition());
    _window.draw(_text);
}

void displayRam(RamInfoModule &_ram, sf::RenderWindow &_window, sf::Text &_text, sf::RectangleShape &_rect)
{
    _ram.refresh();
    std::string res = "Total: " + _ram.getTotal() + " Ko\nAvailable: " + _ram.getAvailable() + " Ko";

    _text.setString(res);
    _text.setPosition(_rect.getPosition());
    _window.draw(_text);
}


void displayCpu(CpuInfoModule &_cpu, sf::RenderWindow &_window, sf::Text &_text, sf::RectangleShape &_rect, std::vector<sf::RectangleShape> &_bar)
{
    _cpu.refresh();
    std::vector<CPUUsage> tempusage = _cpu.getUsage();
    sf::Vector2f pos = _rect.getPosition();
    sf::Vector2f barPos = _bar[0].getPosition();
    size_t sizetmp = tempusage.size();

    pos.y += 5;
    barPos.y = pos.y - 5;
    for (size_t i = 0; i < sizetmp; i++) {
        std::string res = "[" + tempusage[i].nbr + "]";
        _text.setPosition(pos);
        _text.setString(res);
        _window.draw(_text);
        for (int n = 0; n < (int)tempusage[i].active / 3; n++) {
            _bar[n].setPosition(barPos);
            _window.draw(_bar[n]);
            barPos.x += 9;
        }
        barPos.y += 42;
        pos.y += 42;
        barPos.x = _bar[0].getPosition().x;
    }
}

void GraphicMonitorDisplay::displayModules()
{
    DateTimeModule _date;
    HostInfoModule _host;
    NetworkInfoModule _network;
    OSInfoModule _os;
    RamInfoModule _ram;
    CpuInfoModule _cpu;

    displayDate(_date, Window, textInfo, rectModules[0]);
    displayHost(_host, Window, textInfo, rectModules[1]);
    displayNetwork(_network, Window, textInfo, rectModules[2]);
    displayOs(_os, Window, textInfo, rectModules[3]);
    displayRam(_ram, Window, textInfo, rectModules[4]);
    displayCpu(_cpu, Window, textInfo, rectModules[5], progressBar);
}