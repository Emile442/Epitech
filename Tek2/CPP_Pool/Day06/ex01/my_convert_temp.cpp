/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** my_convert_temp
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>

int main(int ac, char** av)
{
    std::string str;
    std::string unit;
    std::stringstream stream;
    float value;

    std::getline(std::cin, str);
    stream << str;
    stream >> value;
    stream >> unit;
    std::transform(unit.begin(), unit.end(), unit.begin(), ::tolower);
    if (unit == "celsius")
        std::cout << std::setw(16) << std::fixed << std::setprecision(3) << (value * 9.0 / 5.0) + 32 << std::setw(16) << "Fahrenheit" << std::endl;
    else if (unit == "fahrenheit")
        std::cout << std::setw(16) << std::fixed << std::setprecision(3) << 5.0 / 9.0 * (value - 32) << std::setw(16) << "Celsius" << std::endl;
}

