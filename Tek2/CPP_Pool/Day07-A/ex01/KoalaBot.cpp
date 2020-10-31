/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(std::string serial) : _serial(serial)
{
}

KoalaBot::~KoalaBot()
{
}

void KoalaBot::setParts(Arms& arms)
{
    this->_arms = arms;
}

void KoalaBot::setParts(Legs& legs)
{
    this->_legs = legs;
}

void KoalaBot::setParts(Head& head)
{
    this->_head = head;
}

void KoalaBot::swapParts(Arms& arms)
{
    Arms tmp = this->_arms;
    
    this->_arms = arms;
    arms = tmp;
}

void KoalaBot::swapParts(Legs& legs)
{
    Legs tmp = this->_legs;
    
    this->_legs = legs;
    legs = tmp;
}

void KoalaBot::swapParts(Head& head)
{
    Head tmp = this->_head;

    this->_head = head;
    head = tmp;
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    this->_arms.informations();
    this->_legs.informations();
    this->_head.informations();
}

bool KoalaBot::status() const
{
    if (this->_arms.isFunctionnal() && this->_legs.isFunctionnal() && this->_head.isFunctionnal())
        return (true);
    return (false);
}
