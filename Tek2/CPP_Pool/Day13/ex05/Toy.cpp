/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Toy.cpp
*/

#include "Toy.hpp"

Toy::Toy() : _type(ToyType::BASIC_TOY), _name("toy"), _picture(), _error()
{

}

Toy::Toy(ToyType toyType, const std::string & name, const std::string & filename)
: _type(toyType), _name(name), _picture(filename), _error()
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
    bool status = _picture.getPictureFromFile(filename);
    if (!status)
        _error.setType(Error::ErrorType::PICTURE);
    return (status);
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

Toy &Toy::operator<<(std::string const &str)
{
    this->_picture.data = str;
    return (*this);
}

bool Toy::speak_es(std::string const &str)
{
    _error.setType(Error::ErrorType::SPEAK);
    (void)str;
    return (false);
}

Toy::Error Toy::getLastError() const
{
    return (_error);
}

std::ostream & operator<<(std::ostream & os, Toy const & ref)
{
    return (os << ref.getName() << std::endl << ref.getAscii() << std::endl);
}


std::string Toy::Error::what() const
{
    if (type == Toy::Error::ErrorType::PICTURE)
        return ("bad new illustration");
    if (type == Toy::Error::ErrorType::SPEAK)
        return ("wrong mode");
    return ("");
}

std::string Toy::Error::where() const
{
    if (type == Toy::Error::ErrorType::PICTURE)
        return ("setAscii");
    if (type == Toy::Error::ErrorType::SPEAK)
        return ("speak_es");
    return ("");
}

void Toy::Error::setType(ErrorType typeErr)
{
    type = typeErr;
}

Toy::Error::Error(ErrorType errorType) : type(errorType)
{
}

Toy::Error::~Error()
{
}
