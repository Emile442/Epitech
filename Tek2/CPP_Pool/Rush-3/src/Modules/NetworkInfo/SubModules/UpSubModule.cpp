/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** UpSubModule.cpp
*/

#include "UpSubModule.hpp"

NetworkInfo::UpSubModule::UpSubModule() : IMonitorSubModule("Up")
{
    init();
}

void NetworkInfo::UpSubModule::refresh()
{
    const std::string cp = "/proc/net/dev";
    std::ifstream file(cp.c_str());
    std::string	str;
    int	a = 0;
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
                if (temp[0] == '0')
                    temp.erase(0, 1);
                _value = temp;
                temp.erase();
            }
        }
    }
    file.close();
}
