/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Fruit.cpp
*/

#include "Fruit.hpp"

Fruit::Fruit(const std::string &name, int vitamin)
: _name(name), _vitamins(vitamin)
{

}

Fruit::~Fruit()
{

}

std::string Fruit::getName() const
{
    return _name;
}

void Fruit::setName(const std::string &name)
{
    _name = name;
}

int Fruit::getVitamins() const
{
    return _vitamins;
}

void Fruit::setVitamins(int vitamin)
{
    _vitamins = vitamin;
}

