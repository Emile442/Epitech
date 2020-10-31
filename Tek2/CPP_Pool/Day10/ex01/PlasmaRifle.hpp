/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** PlasmaRifle.hpp
*/


#ifndef PLASMARIFLE_H_
#define PLASMARIFLE_H_

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon{
    public:
        PlasmaRifle();
        virtual ~PlasmaRifle();
        virtual void attack() const;

};

#endif //PLASMARIFLE_H_
