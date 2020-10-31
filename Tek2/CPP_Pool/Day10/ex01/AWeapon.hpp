/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** AWeapon.hpp
*/


#ifndef AWEAPON_H_
#define AWEAPON_H_

#include <string>
#include <iostream>

class AWeapon {
    public:
        AWeapon(const std::string &name, int apcost, int damage);
        virtual ~AWeapon();

        std::string const & getName() const;
        int getAPCost() const;
        int getDamage() const;

        virtual void attack() const = 0;

    private:
        std::string _name;
        int _apCost;
        int _damage;
};

#endif //AWEAPON_H_
