/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** Errors.cpp
*/

#include "Errors.hpp"

NasaError::NasaError(const std::string &message, const std::string &component)
: _message(message), _component(component)
{

}

std::string const &NasaError::getComponent() const
{
    return (_component);
}

const char* NasaError::what() const throw() {
    return (_message.c_str());
}

MissionCriticalError::MissionCriticalError(std::string const &message, const std::string &component)
: NasaError(message, component)
{

}

LifeCriticalError::LifeCriticalError(std::string const &message, const std::string &component)
: NasaError(message, component)
{

}

UserError::UserError(std::string const &message, const std::string &component)
: NasaError(message, component)
{

}

CommunicationError::CommunicationError(std::string const &message)
: NasaError(message, "CommunicationDevice")
{
    
}
