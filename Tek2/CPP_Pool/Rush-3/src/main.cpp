/*
** EPITECH PROJECT, 2018
** main.cpp
** File description:
** main.cpp
*/

#include "../app/Class/GraphicMonitorDisplay.hpp"
#include "../app/Class/TextMonitorDisplay.hpp"

int main(int ac, char **av)
{
    std::string str = av[1];

    if (ac != 2)
        return (-1);
    if (str == "Graphic") {
        GraphicMonitorDisplay Graphic;
        Graphic.initWindow();
        Graphic.displayWindow();
    } else if (str == "Text") {
        if (ncurses() == -1)
            return (-1);
    } else {
        std::cout << "Bad parameters!" << std::endl;
        return (-1);
    }
    return (0);
}