/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Sorcerer.hpp
*/

#ifndef SORCERER_H_
#define SORCERER_H_

#include <string>
#include <iostream>

#include "Victim.hpp"

class Sorcerer {
    public:
        Sorcerer(std::string name, std::string title);
        ~Sorcerer();
        std::string getName() const;
        std::string getTitle() const;
        void polymorph(const Victim &victim) const;

    protected:
    private:
        std::string _name;
        std::string _title;
};

std::ostream & operator<<(std::ostream&, Sorcerer const &ref);

#endif //CPP_D10_2019_SORCERER_HPP
