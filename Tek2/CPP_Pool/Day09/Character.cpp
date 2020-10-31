/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level)
: Range(AttackRange::CLOSE), _name(name), _strength(5), _stamina(5), _intelligence(5), _spirit(5),
_agility(5), _power(100), _pv(100), _level(level)
{
    std::cout << _name << " Created" << std::endl;
}

Character::~Character()
{
}

const std::string & Character::getName() const
{
    return (this->_name);
}

int Character::getLvl() const
{
    return (this->_level);
}

int Character::getPv() const
{
    return (this->_pv);
}

int Character::getPower() const
{
    return (this->_power);
}

bool Character::canAttack(int required)
{
    if (this->_power >= required)
        return (true);
    std::cout << this->_name << " out of power" << std::endl;
    return false;
}

int Character::CloseAttack()
{
    if (!this->canAttack(10))
        return (0);

    this->_power -= 10;
    std::cout << this->_name << " strikes with a wooden stick" << std::endl;
    return (10 + this->_strength);
}

int Character::RangeAttack()
{
    if (!this->canAttack(10))
        return (0);

    this->_power -= 10;
    std::cout << this->_name << " tosses a stone" << std::endl;
    return (5 + this->_strength);
}

void Character::Heal()
{
    if (this->_pv + 50 >= 100)
        this->_pv = 100;
    else
        this->_pv += 50;
    std::cout << this->_name << " takes a potion" << std::endl;
}

void Character::RestorePower()
{
    this->_power = 100;
    std::cout << this->_name << " eats" << std::endl;
}

void Character::TakeDamage(int damage)
{
    this->_pv -= damage;

    if (this->_pv > 0)
        std::cout << this->_name << " takes " << damage << " damage" << std::endl;

    if (this->_pv <= 0) {
        this->_pv = 0;
        std::cout << this->_name << " out of combat" << std::endl;
    }
}

//int main () {
//    Character c("poney", 42);
//    c.TakeDamage(50);
//    c.TakeDamage(200);
//    c.TakeDamage(200);
//}