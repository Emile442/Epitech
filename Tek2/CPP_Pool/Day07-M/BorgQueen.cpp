/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** BorgQueen
*/

#include "BorgQueen.hpp"

Borg::BorgQueen::BorgQueen()
{
    this->movePtr = &Borg::Ship::move;
    this->firePtr = &Borg::Ship::fire;
    this->destroyPtr = &Borg::Ship::fire;
}

Borg::BorgQueen::~BorgQueen()
{
}

bool Borg::BorgQueen::move(Borg::Ship *ship, Destination dest)
{
    return (ship->*this->movePtr)(dest);
}

void Borg::BorgQueen::fire(Borg::Ship *ship, Federation::Starfleet::Ship *target)
{
    (ship->*this->firePtr)(target);
}

void Borg::BorgQueen::destroy(Borg::Ship *ship, Federation::Ship *target)
{
    (ship->*this->destroyPtr)(target);
}