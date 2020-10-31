/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** Droid
*/

#include "Droid.hpp"

/**
 * @brief Construct a new Droid:: Droid object
 * 
 * @param serial 
 */
Droid::Droid(std::string serial, size_t energy, const size_t attack, const size_t toughness, std::string* status)
    : _serial(serial), _energy(energy), _attack(attack), _toughness(toughness), _status(status)
{
    this->_battleData = new DroidMemory();
    std::cout << "Droid '" << _serial << "' Activated" << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '" << _serial << "' Destroyed" << std::endl;
    delete _status;
    delete _battleData;
}

Droid::Droid(const Droid &ref) 
: _serial(ref.getId()), _energy(50), _attack(ref.getAttack()), _toughness(ref.getToughness()), _status(new std::string(ref.getStatus())), _battleData(new DroidMemory(*ref.getBattleData()))
{
    this->_battleData = new DroidMemory(*ref.getBattleData());
    std::cout << "Droid '" << _serial << "' Activated, Memory Dumped" << std::endl;
}

Droid &Droid::operator=(const Droid &ref)
{    
    if (this == &ref)
        return (*this);
    
    this->setId(ref.getId());
    this->setEnergy(ref.getEnergy());

    if (this->_status)
        delete this->_status;
    this->setStatus(new std::string(ref.getStatus()));
    return (*this);
}

std::string Droid::getId() const
{
    return (this->_serial);
}

void Droid::setId(std::string serial)
{
    this->_serial = serial;
}

size_t Droid::getEnergy() const
{
    return (this->_energy);
}

void Droid::setEnergy(size_t energy)
{
    if (energy >= 0  && energy <= 100)
        this->_energy = energy;
    if (energy > 100)
        this->_energy = 100;
            
}

size_t Droid::getAttack() const
{
    return (this->_attack);
}

size_t Droid::getToughness() const
{
    return (this->_toughness);
}

std::string & Droid::getStatus() const
{
    return (*this->_status);
}

void Droid::setStatus(std::string* status)
{
    this->_status = status;
}

bool Droid::operator==(const Droid &ref) const
{
    if (this->_status->compare(ref.getStatus()) == 0)
        return (true);
    return (false);
}

bool Droid::operator!=(const Droid &ref) const
{
    if (this->_status->compare(ref.getStatus()) != 0)
        return (true);
    return (false);
}

Droid & Droid::operator<<(size_t &reload)
{
    if (this->_energy > 100)
        return (*this);
        
    size_t need = 100 - this->_energy;

    if (this->_energy < 100){
        if (need > reload)
            need = reload;
        this->_energy += need;
        reload -= need;
    }
    return (*this);
}

std::ostream& operator <<(std::ostream& os, Droid const& ref)
{
  os << "Droid '" << ref.getId() << "', " << ref.getStatus() << ", " << ref.getEnergy();
  return (os);
}

DroidMemory* Droid::getBattleData() const
{
    if (this->_battleData)
        return (this->_battleData);
    return (NULL);
}

void Droid::setBattleData(DroidMemory* battleData)
{
    this->_battleData = battleData;
}

bool Droid::operator()(std::string const * task, size_t exp)
{
    if (this->_energy <= 10) {
        this->setStatus(new std::string("Battery Low"));
        this->_energy = 0;
        return (false);
    }

    this->_energy -= 10;

    if (this->_battleData->getExp() < exp) {
        this->setStatus(new std::string(*task + " - Failed!"));
        this->_battleData->setExp(this->_battleData->getExp() + exp);
        return (false);
    }
    this->setStatus(new std::string(*task + " - Completed!"));
    this->_battleData->setExp(this->_battleData->getExp() + exp / 2);
    return (true);
}