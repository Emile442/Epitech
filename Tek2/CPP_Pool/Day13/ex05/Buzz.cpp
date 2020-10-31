/*
** EPITECH PROJECT, 2020
** ex02
** File description:
** Buzz.cpp
*/

#include "Buzz.hpp"


Buzz::Buzz(const std::string &name, const std::string &filename)
: Toy(ToyType::BUZZ, name, filename)
{

}

Buzz::~Buzz()
{

}

void Buzz::speak(std::string const &str)
{
    std::cout << "BUZZ: "<< getName() << " \"" << str <<"\"" << std::endl;
}

bool Buzz::speak_es(std::string const & str)
{
    std::cout << "BUZZ: " << getName() << " senorita \"" << str << "\" senorita" << std::endl;
    return (true);
}