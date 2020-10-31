/*
** EPITECH PROJECT, 2020
** cpp_d07m_2019
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

/**
 * @brief Construct a new Warp System:: Quantum Reactor:: Quantum Reactor object
 * 
 */
WarpSystem::QuantumReactor::QuantumReactor()
{
    _stability = true;
}

WarpSystem::QuantumReactor::~QuantumReactor()
{
}

bool WarpSystem::QuantumReactor::isStable()
{
    return (this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}

/**
 * @brief Construct a new Warp System:: Core:: Core object
 * 
 * @param coreReactor 
 */
WarpSystem::Core::Core(QuantumReactor * coreReactor) : _coreReactor(coreReactor)
{
}

WarpSystem::Core::~Core()
{

}

WarpSystem::QuantumReactor* WarpSystem::Core::checkReactor()
{
    return (this->_coreReactor);
}