/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** Federation
*/

#include "Federation.hpp"

/**
 * @brief Construct a new Federation:: Starfleet:: Ship:: Ship object
 * 
 * @param length 
 * @param width 
 * @param name 
 * @param maxWarp 
 */
Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp, int torpedo) : _length(length), _width(width), _name(name), _maxWarp(maxWarp), _home(Destination::EARTH), _location(_home), _shield(100), _photonTorpedo(torpedo)
{
    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
    if (_photonTorpedo != 0)
        std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core* core)
{
    this->_core = core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

bool Federation::Starfleet::Ship::checkCore()
{
    std::string reactorStatus = this->_core->checkReactor()->isStable() ? "stable" : "unstable";

    std::cout << "USS " << this->_name << ": The core is " << reactorStatus << " at the time." << std::endl;
    return (this->_core->checkReactor());
}

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain* captain)
{
    this->_captain = captain;
    std::cout << captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." << std::endl;
}

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (d != this->_location && this->_core->checkReactor()->isStable() == true && warp <= this->_maxWarp)
        this->_location = d;
    else 
        return (false);

    return (true);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    return (Federation::Starfleet::Ship::move(warp, this->_home));
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    return (Federation::Starfleet::Ship::move(this->_maxWarp, d));
}

bool Federation::Starfleet::Ship::move()
{
    return (Federation::Starfleet::Ship::move(this->_maxWarp, this->_home));
}

int Federation::Starfleet::Ship::getShield()
{
    return (this->_shield);
}

void Federation::Starfleet::Ship::setShield(int shield)
{
    this->_shield = shield;
}

int Federation::Starfleet::Ship::getTorpedo()
{
    return (this->_photonTorpedo);
}

void Federation::Starfleet::Ship::setTorpedo(int torpedo)
{
    this->_photonTorpedo = torpedo;
}

void Federation::Starfleet::Ship::fire(Borg::Ship *target)
{
    Federation::Starfleet::Ship::fire(1, target);
}

void Federation::Starfleet::Ship::fire(int torpedoes , Borg::Ship *target)
{
    if (torpedoes > this->_photonTorpedo) {
        std::cout << this->_name << ": No enough torpedoes to fire, " << this->_captain->getName() << "!" << std::endl;
        return;
    }
    this->_photonTorpedo -= torpedoes;
    
    target->setShield(target->getShield() - (50 * torpedoes));

    if (this->_photonTorpedo > 0)
        std::cout << this->_name << ": Firing on target. " << this->_photonTorpedo << " torpedoes remaining." << std::endl;
    else
        std::cout << this->_name << ": No more torpedo to fire, " << this->_captain->getName() << "!" << std::endl;
}

/**
 * @brief Construct a new Federation:: Ship:: Ship object
 * 
 * @param length 
 * @param width 
 * @param name 
 */
Federation::Ship::Ship(int length, int width, std::string name) : _length(length), _width(width), _name(name), _maxWarp(1), _home(Destination::VULCAN), _location(_home)
{
    std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{

}

void Federation::Ship::setupCore(WarpSystem::Core* core)
{
    this->_core = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

bool Federation::Ship::checkCore()
{
    std::string reactorStatus = this->_core->checkReactor()->isStable() ? "stable" : "unstable";

    std::cout << this->_name << ": The core is " << reactorStatus << " at the time." << std::endl;
    return (this->_core->checkReactor()->isStable());
}


bool Federation::Ship::move(int warp, Destination d)
{
    if (d != this->_location && this->_core->checkReactor()->isStable() == true && warp <= this->_maxWarp)
        this->_location = d;
    else 
        return (false);

    return (true);
}

bool Federation::Ship::move(int warp)
{
    return (Federation::Ship::move(warp, this->_home));
}

bool Federation::Ship::move(Destination d)
{
    return (Federation::Ship::move(this->_maxWarp, d));
}

bool Federation::Ship::move()
{
    return (Federation::Ship::move(this->_maxWarp, this->_home));
}

WarpSystem::Core* Federation::Ship::getCore()
{
    return (this->_core);
}

/**
 * @brief Construct a new Federation:: Starfleet:: Captain:: Captain object
 * 
 * @param name 
 */
Federation::Starfleet::Captain::Captain (std::string name) : _name(name)
{

}

Federation::Starfleet::Captain::~Captain()
{

}

void Federation::Starfleet::Captain::setAge(int age)
{
    this->_age = age;
}

std::string Federation::Starfleet::Captain::getName()
{
    return (this->_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return (this->_age);
}

/**
 * @brief Construct a new Federation:: Starfleet:: Ensign:: Ensign object
 * 
 * @param name 
 */
Federation::Starfleet::Ensign::Ensign(std::string name) : _name(name)
{
    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{

}
