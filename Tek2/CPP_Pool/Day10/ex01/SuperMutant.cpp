/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** SuperMutant.cpp
*/

#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
: AEnemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::takeDamage(int damage)
{
    damage -= 3;

    if (damage < 0)
        return;
    _hp -= damage;
}
