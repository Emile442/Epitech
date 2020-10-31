/*
** EPITECH PROJECT, 2022
** Tek2
** File description:
** Created by Zebens,
*/

#include "Teddy.hpp"

Teddy::Teddy(std::string const& name) : Toy(name)
{

}

Teddy::~Teddy()
{

}

void Teddy::isTaken()
{
    std::cout << "gra hu" << std::endl;
}