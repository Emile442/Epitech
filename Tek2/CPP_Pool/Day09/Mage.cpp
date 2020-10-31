/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Mage.cpp
*/

#include "Mage.hpp"

Mage::Mage(const std::string &name, int level)
: Character(name, level)
{
    this->_strength = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agility = 7;
    std::cout << _name << " teleported" << std::endl;
}

Mage::~Mage()
{

}

int Mage::CloseAttack()
{
    if (!this->canAttack(10))
        return (0);
    this->_power -= 10;
    std::cout << this->_name << " blinks" << std::endl;
    this->Range = Character::RANGE;
    return (0);
}

int Mage::RangeAttack()
{
    if (!this->canAttack(25))
        return (0);
    this->_power -= 25;
    std::cout << _name << " launches a fire ball" << std::endl;
    return (20 + this->_spirit);
}

void Mage::RestorePower()
{
    int HowToAdd = 50 + this->_intelligence;

    if (this->_power + HowToAdd >= 100)
        this->_power = 100;
    else
        this->_power += HowToAdd;

    std::cout << this->_name << " takes a mana potion" << std::endl;
}
