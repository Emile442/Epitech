/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Character.cpp
*/

#include "Character.hpp"

Character::Character(const std::string &name)
: _name(name), _ap(40)
{
    this->_weapon = nullptr;
}

Character::~Character()
{
}

std::string const &Character::getName() const
{
    return (_name);
}

void Character::equip(AWeapon *weapon)
{
    _weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
    if (!_weapon || !enemy) {
        return;
    }
    if (_ap >= _weapon->getAPCost()) {
        removeAp(_weapon->getAPCost());
        enemy->takeDamage(_weapon->getDamage());
        std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
        _weapon->attack();
        if (enemy->getHP() <= 0)
            delete enemy;
    }
}

void Character::recoverAP()
{
    if (_ap + 10 >= 40)
        _ap = 40;
    else
        _ap +=10;
}

void Character::removeAp(int nbr)
{
    if (nbr < 0)
        return;
    if (_ap - nbr < 0)
        _ap = 0;
    else
        _ap -= nbr;
}

int Character::getAp() const
{
    return (_ap);
}

AWeapon* Character::getWeapon() const
{
    return (_weapon);
}

std::ostream& operator <<(std::ostream& os, Character const& ref)
{
    if (ref.getWeapon())
        os << ref.getName() << " has " << ref.getAp() << " AP and wields a " << ref.getWeapon()->getName() << std::endl;
    else
        os << ref.getName() << " has " << ref.getAp() << " AP and is unarmed" << std::endl;
    return (os);
}
