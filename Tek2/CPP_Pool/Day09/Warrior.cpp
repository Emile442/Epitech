/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Warrior
*/

#include "Warrior.hpp"

Warrior::Warrior(const std::string &name, int lvl)
: Character(name, lvl), _weaponName("hammer")
{
    this->_strength = 12;
    this->_stamina = 12;
    this->_intelligence = 6;
    this->_spirit = 5;
    this->_agility = 7;
    std::cout << "I'm " << name << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior()
{
}

int Warrior::CloseAttack()
{
    if (!this->canAttack(30))
        return (0);

    this->_power -= 30;
    std::cout << this->_name << " strikes with his " << this->_weaponName << std::endl;
    return (20 + this->_strength);
}

int Warrior::RangeAttack()
{
    if (!this->canAttack(10))
        return (0);

    this->_power -= 10;
    std::cout << this->_name << " intercepts" << std::endl;
    this->Range = Character::CLOSE;
    return (5 + this->_strength);
}


