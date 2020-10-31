/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy() : _type(ToyType::BASIC_TOY), _name("toy"), _picture()
{

}

Toy::Toy(ToyType toyType, const std::string & name, const std::string & filename)
: _type(toyType), _name(name), _picture(filename)
{

}

Toy::Toy(Toy const &ref)
: _type(ref._type), _name(ref._name)
{
    _picture = ref._picture;
}


Toy::~Toy()
{

}

Toy::ToyType Toy::getType() const
{
    return (_type);
}

std::string Toy::getName() const
{
    return (_name);
}

void Toy::setName(const std::string &name)
{
    _name = name;
}

bool Toy::setAscii(const std::string &filename)
{
    return (_picture.getPictureFromFile(filename));
}

std::string Toy::getAscii() const
{
    return (_picture.data);
}

Toy &Toy::operator=(Toy const &ref)
{
    this->_type = ref._type;
    this->_name = ref._name;
    this->_picture = ref._picture;
    return (*this);
}

void Toy::speak(std::string const &str)
{
    std::cout << _name << " \"" << str << "\"" << std::endl;
}

