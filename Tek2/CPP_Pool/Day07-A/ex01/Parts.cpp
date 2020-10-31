/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** Parts
*/

#include "Parts.hpp"

/**
 * @brief Construct a new Arms:: Arms object
 * 
 * @param serial 
 * @param functionnal 
 */
Arms::Arms(std::string serial, bool functionnal) : _serial(serial), _functionnal(functionnal)
{
}

Arms::~Arms()
{
}

bool Arms::isFunctionnal() const
{
    return (this->_functionnal);
}

std::string Arms::serial() const
{
    return (this->_serial);
}

void Arms::informations() const
{
    std::string strStatus = this->_functionnal ? "OK" : "KO";

    std::cout << "\t[Parts] Arms "<< this->_serial << " status : " << strStatus << std::endl;
}

/**
 * @brief Construct a new Legs:: Legs object
 * 
 * @param serial 
 * @param functionnal 
 */
Legs::Legs(std::string serial, bool functionnal) : _serial(serial), _functionnal(functionnal)
{
}

Legs::~Legs()
{
}

bool Legs::isFunctionnal() const
{
    return (this->_functionnal);
}

std::string Legs::serial() const
{
    return (this->_serial);
}

void Legs::informations() const
{
    std::string strStatus = this->_functionnal ? "OK" : "KO";

    std::cout << "\t[Parts] Legs "<< this->_serial << " status : " << strStatus << std::endl;
}

/**
 * @brief Construct a new Head:: Head object
 * 
 * @param serial 
 * @param functionnal 
 */
Head::Head(std::string serial, bool functionnal) : _serial(serial), _functionnal(functionnal)
{
}

Head::~Head()
{
}

bool Head::isFunctionnal() const
{
    return (this->_functionnal);
}

std::string Head::serial() const
{
    return (this->_serial);
}

void Head::informations() const
{
    std::string strStatus = this->_functionnal ? "OK" : "KO";

    std::cout << "\t[Parts] Head "<< this->_serial << " status : " << strStatus << std::endl;
}