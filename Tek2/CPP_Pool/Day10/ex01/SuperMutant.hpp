/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** SuperMutant.hpp
*/


#ifndef SUPERMUTANT_H_
#define SUPERMUTANT_H_


#include "AEnemy.hpp"

class SuperMutant : public AEnemy {
    public:
        SuperMutant();
        ~SuperMutant();
        virtual void takeDamage(int damage);

    private:
};


#endif //CPP_D10_2019_SUPERMUTANT_HPP
