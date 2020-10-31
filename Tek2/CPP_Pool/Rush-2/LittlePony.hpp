/*
** EPITECH PROJECT, 2019
** LittlePony.hpp
** File description:
** LittlePony Header
*/

#ifndef _LITTLEPONY_HPP_
#define _LITTLEPONY_HPP_

#include "Object.hpp"
#include "Toy.hpp"

class LittlePony : public Toy {
    public:
        LittlePony(std::string const& title);
        ~LittlePony();
        virtual void isTaken();
};

#endif