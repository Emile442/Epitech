/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** DroidMemory
*/

#include "DroidMemory.hpp"

DroidMemory::DroidMemory(size_t exp, size_t fingerprint) : _exp(exp)
{
    this->FingerPrint = random();
}

DroidMemory::DroidMemory(const DroidMemory &ref) : _exp(ref.getExp()), _fingerprint(ref.getFingerprint())
{
}

DroidMemory::~DroidMemory()
{

}

void DroidMemory::setFingerprint(size_t fingerprint)
{
    this->_fingerprint = fingerprint;
}

size_t DroidMemory::getFingerprint() const
{
    return (this->_fingerprint);
}

void DroidMemory::setExp(size_t exp)
{
    this->_exp = exp;
}

size_t DroidMemory::getExp() const
{
    return (this->_exp);
}

DroidMemory DroidMemory::operator<<(const DroidMemory &ref)
{
    this->_exp += ref.getExp();
    this->_fingerprint = this->_fingerprint ^ ref.getFingerprint();

    return (*this);
}

DroidMemory DroidMemory::operator>>(DroidMemory &ref) const
{
    ref._exp += this->getExp();
    ref._fingerprint = this->getFingerprint() ^ ref._fingerprint;
    return (*this);
}

DroidMemory DroidMemory::operator+=(const DroidMemory &ref)
{
    return DroidMemory::operator<<(ref);
}

DroidMemory DroidMemory::operator+=(const size_t size)
{
    this->_exp += size;
    this->_fingerprint = this->_fingerprint ^ size;
    return (*this);
}

DroidMemory & DroidMemory::operator+(const DroidMemory &ref)
{
    DroidMemory* tmp = new DroidMemory();

    tmp->_exp = this->_exp + ref._exp;
    this->_fingerprint = this->_fingerprint ^ref._fingerprint;
    return (*tmp);
}

DroidMemory & DroidMemory::operator+(const size_t size)
{
    DroidMemory* tmp = new DroidMemory();

    tmp->_exp = this->_exp + size;
    tmp->_fingerprint = this->_fingerprint ^size;
    return (*tmp);
}

std::ostream& operator <<(std::ostream& os, DroidMemory const& ref)
{
  os << "DroidMemory '" << ref.getFingerprint() << "', " << ref.getExp();
  return (os);
}

bool DroidMemory::operator==(const DroidMemory &ref) const
{
    if (this->_exp == ref._exp && this->_fingerprint == ref._fingerprint)
        return (true);
    return (false);
}

bool DroidMemory::operator!=(const DroidMemory &ref) const
{
    if (this->_exp != ref._exp || this->_fingerprint != ref._fingerprint)
        return (true);
    return (false);
}

bool DroidMemory::operator<(DroidMemory const &ref) const
{
    if (this->_exp < ref._exp)
        return (true);
    return (false);
}

bool DroidMemory::operator<(const size_t ref) const
{
    if (this->_exp < ref)
        return (true);
    return (false);
}

bool DroidMemory::operator>(DroidMemory const &ref) const
{
    if (this->_exp > ref._exp)
        return (true);
    return (false);
}

bool DroidMemory::operator>(const size_t ref) const
{
    if (this->_exp > ref)
        return (true);
    return (false);
}

bool DroidMemory::operator<=(DroidMemory const &ref) const
{
    if (this->_exp <= ref._exp)
        return (true);
    return (false);
}

bool DroidMemory::operator<=(const size_t ref) const
{
    if (this->_exp <= ref)
        return (true);
    return (false);
}

bool DroidMemory::operator>=(DroidMemory const &ref) const
{
    if (this->_exp >= ref._exp)
        return (true);
    return (false);
}

bool DroidMemory::operator>=(const size_t ref) const
{
    if (this->_exp >= ref)
        return (true);
    return (false);
}

// int main ()
// {
//     DroidMemory mem1;
//     mem1 += 42;

//     DroidMemory mem2 = mem1;
//     std::cout << mem1 << std::endl;

//     DroidMemory mem3; 
//     mem3 << mem1; 
//     mem3 >> mem1;
//     mem3 << mem1;

//     std::cout << mem3  << std::endl;
//     std::cout << mem1 << std::endl;
// }
