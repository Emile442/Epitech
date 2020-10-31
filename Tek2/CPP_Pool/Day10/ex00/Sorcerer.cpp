/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Sorcerer.cpp
*/

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title)
: _name(name), _title(title)
{
    std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::getName() const
{
    return (_name);
}

std::string Sorcerer::getTitle() const
{
    return (_title);
}

void Sorcerer::polymorph(const Victim &victim) const
{
    victim.getPolymorphed();
}

std::ostream& operator <<(std::ostream& os, Sorcerer const& ref)
{
    os << "I am " << ref.getName() << ", " << ref.getTitle() << ", and I like ponies!" << std::endl;
    return (os);
}

//int main (void) {
//    Sorcerer robert("Robert", "the Magnificent");
//    Victim jim("Jimmy");
//    Peon joe("Joe");
//
//    std::cout << robert << jim << joe;
//    robert.polymorph(jim);
//    robert.polymorph(joe);
//    return (0);
//}

