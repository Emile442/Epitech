/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Peon.hpp
*/

#ifndef PEON_H_
#define PEON_H_

#include "Victim.hpp"

class Peon : public Victim {
    public:
        Peon(std::string name);
        ~Peon();
        void getPolymorphed() const;

    protected:
    private:
};

#endif //CPP_D10_2019_PEON_HPP
