/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Priest.cpp
*/

#include "Priest.hpp"

Priest::Priest(const std::string &name, int level)
: Mage(name, level)
{
    this->_strength = 4;
    this->_stamina = 4;
    this->_intelligence = 42;
    this->_spirit = 21;
    this->_agility = 2;
    std::cout << this->_name << " enters in the order" << std::endl;
}

Priest::~Priest()
{

}

int Priest::CloseAttack()
{
    if (!this->canAttack(10))
        return (0);
    this->_power -= 10;
    std::cout << this->_name << " uses a spirit explosion" << std::endl;
    this->Range = Character::RANGE;
    return (10 + this->_spirit);
}

void Priest::Heal()
{
    if (!this->canAttack(10))
        return;
    this->_power -= 10;
    if (this->_pv + 70 >= 100)
        this->_pv = 100;
    else
        this->_pv += 70;

    std::cout << this->_name << " casts a little heal spell" << std::endl;
}


