/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Victim.hpp
*/

#ifndef VICTIM_H_
#define VICTIM_H_

#include <string>
#include <iostream>

class Victim {
    public:
        Victim(std::string name);
        virtual ~Victim();
        std::string getName() const;

        virtual void getPolymorphed() const;

    protected:
    private:
        std::string _name;
};

std::ostream & operator<<(std::ostream&, Victim const &ref);

#endif //CPP_D10_2019_VICTIM_HPP
