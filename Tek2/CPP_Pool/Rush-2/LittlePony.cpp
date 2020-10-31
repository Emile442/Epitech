/*
** EPITECH PROJECT, 2022
** Tek2
** File description:
** Created by Zebens,
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(std::string const& title) : Toy(title)
{}

LittlePony::~LittlePony()
{

}

void LittlePony::isTaken()
{
    std::cout << "yo man" << std::endl;
}