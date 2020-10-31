/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** KreogCom
*/

#include "KreogCom.hpp"

KreogCom::KreogCom(int x, int y, int serial) : _x(x), _y(y), _serial(serial)
{
    this->next = 0;
    std::cout << "KreogCom " << _serial << " initialisated" << std::endl;
}

KreogCom::~KreogCom()
{
    std::cout << "KreogCom " << _serial << " shutting down" << std::endl;
}

void KreogCom::addCom(int x, int y, int serial)
{
    KreogCom *newElem = new KreogCom(x, y, serial);

    newElem->next = this->next;
    this->next = newElem;
}

KreogCom *KreogCom::getCom()
{
    if (this->next)
        return (this->next);
    return (NULL);
}

void KreogCom::removeCom()
{
    KreogCom *supElem;

    if (!this->next)
        return;
    supElem = this->next;
    this->next = this->next->next;
    delete supElem;
}

void KreogCom::ping() const
{
    std::cout << "KreogCom " << this->_serial << " currently at " << this->_x << " " << this->_y << std::endl;
}

void KreogCom::locateSquad() const
{
    if (this->next)
        this->next->locateSquad();	
    this->ping();
}

// int main () {
//     KreogCom k(42, 42, 101010);

//     k.addCom(56, 25, 65);
//     k.addCom(73, 34, 51);
//     k.locateSquad();
//     k.removeCom();
//     k.removeCom();
//     return (0);
// }