/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** DownSubModule.cpp
*/

#include "DownSubModule.hpp"

NetworkInfo::DownSubModule::DownSubModule() : IMonitorSubModule("Down")
{
    init();
}

void NetworkInfo::DownSubModule::refresh()
{
    std::string cp = "/proc/net/dev";
    std::ifstream file(cp.c_str());
    std::string	str;
    int	a = 0;
    int	i = 0;
    std::string	temp;

    while (std::getline(file, str)) {
        if ((a = str.find(":")) != -1) {
            a++;
            while (str[a] == ' ')
                a++;
            while (str[a] != ' ') {
                temp += str[a];
                a++;
            }
            if (std::stoi(temp) > 0) {
                temp.erase();
                while (i != 7) {
                    while (str[a] == ' ')
                        a++;
                    while (str[a] != ' ')
                        a++;
                    i++;
                }
                i = 0;
                while (str[a] == ' ')
                    a++;
                while (str[a] != ' ') {
                    temp += str[a];
                    a++;
                }
                _value = temp;
            }
        }
        temp.erase();
    }
    file.close();
}
