/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** AWeapon.cpp
*/

#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
: _name(name), _apCost(apcost), _damage(damage)
{
}

AWeapon::~AWeapon()
{
}

std::string const & AWeapon::getName() const
{
    return (_name);
}

int AWeapon::getAPCost() const
{
    return (_apCost);
}

int AWeapon::getDamage() const
{
    return (_damage);
}

void AWeapon::attack() const
{
}