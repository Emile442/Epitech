/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** Borg
*/

#include "Federation.hpp"
#include "Borg.hpp"


/**
 * @brief Construct a new Borg:: Ship:: Ship object
 * 
 */
Borg::Ship::Ship(int weaponFrequency, short repair) : _side(300), _maxWarp(9), _home(Destination::UNICOMPLEX), _location(_home), _shield(100), _weaponFrequency(weaponFrequency), _repair(repair)
{
    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core* core)
{
    this->_core = core;
}

bool Borg::Ship::checkCore()
{
    if (this->_core->checkReactor()->isStable())
        std::cout << "Everything is in order." << std::endl;
    else
        std::cout << "Critical failure imminent." << std::endl;

    return (this->_core->checkReactor()->isStable());
}

bool Borg::Ship::move(int warp, Destination d)
{
    if (d != this->_location && this->_core->checkReactor()->isStable() == true && warp <= this->_maxWarp)
        this->_location = d;
    else 
        return (false);

    return (true);
}

bool Borg::Ship::move(int warp)
{
    return (Borg::Ship::move(warp, this->_home));
}

bool Borg::Ship::move(Destination d)
{
    return (Borg::Ship::move(this->_maxWarp, d));
}

bool Borg::Ship::move()
{
    return (Borg::Ship::move(this->_maxWarp, this->_home));
}

int Borg::Ship::getShield()
{
    return (this->_shield);
}

void Borg::Ship::setShield(int shield)
{
    this->_shield = shield;
}

int Borg::Ship::getWeaponFrequency()
{
    return (this->_weaponFrequency);
}

void Borg::Ship::setWeaponFrequency(int frequency)
{
    this->_weaponFrequency = frequency;
}

short Borg::Ship::getRepair()
{
    return (this->_repair);
}

void Borg::Ship::setRepair(short repair)
{
    this->_repair = repair;
}

void Borg::Ship::fire(Federation::Starfleet::Ship *target)
{
    target->setShield(target->getShield() - this->_weaponFrequency);
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::fire(Federation::Ship *target)
{
    target->getCore()->checkReactor()->setStability(false);
    std::cout << "Firing on target with " << this->_weaponFrequency << "GW frequency." << std::endl;
}

void Borg::Ship::repair()
{
    this->_repair -= 1;

    if (this->_repair > 0) {
        this->_shield = 100;
        std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    } else {
        std::cout << "Energy cells depleted , shield weakening." << std::endl;
    }
}