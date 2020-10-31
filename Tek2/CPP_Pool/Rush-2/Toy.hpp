//
// Created by aguichet on 1/25/20.
//

#ifndef CPP_RUSH2_2019_TOY_HPP
#define CPP_RUSH2_2019_TOY_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Object.hpp"

class Toy : public Object {
    public:
        Toy(const std::string &title);
        ~Toy();
        void isTaken() const;
};

#endif //CPP_RUSH2_2019_TOY_HPP
