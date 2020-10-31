/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Mage.hpp
*/

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include <string>
#include <iostream>

#include "Character.hpp"

class Mage : public Character {
    public:
        Mage(const std::string &name, int level);
        ~Mage();
        int CloseAttack();
        int RangeAttack();
        void RestorePower();
};


#endif //MAGE_HPP_
