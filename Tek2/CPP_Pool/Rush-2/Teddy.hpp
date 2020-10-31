/*
** EPITECH PROJECT, 2019
** Teddy.hpp
** File description:
** Teddy Header
*/

#ifndef _TEDDY_HPP_
#define _TEDDY_HPP_

#include "Object.hpp"
#include "Toy.hpp"

class Teddy : public Toy {
    public:
        Teddy(std::string const& name);
        ~Teddy();
        virtual void isTaken();
};

#endif
