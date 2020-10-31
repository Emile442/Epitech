/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** PowerFist.hpp
*/


#ifndef POWERFIST_H_
#define POWERFIST_H_

#include "AWeapon.hpp"

class PowerFist : public AWeapon {
    public:
        PowerFist();
        virtual ~PowerFist();
        virtual void attack() const;
};


#endif //CPP_D10_2019_POWERFIST_HPP
