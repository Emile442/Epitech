/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Priest.hpp
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include <string>
#include <iostream>

#include "Mage.hpp"

class Priest : public Mage {
    public:
        Priest(const std::string &name, int level);
        ~Priest();
        int CloseAttack();
        void Heal();

    protected:
    private:
};


#endif //PRIEST_HPP_
