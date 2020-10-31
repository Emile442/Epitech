/*
** EPITECH PROJECT, 2019
** Box.hpp
** File description:
** Box Header
*/

#ifndef _BOX_HPP_
#define _BOX_HPP_

#include "Wrap.hpp"
#include "Object.hpp"

class Box : public Wrap, public Object
{
    public:
        Box(const std::string &Title);
        ~Box();
        virtual bool BoxIsOpen();
        bool WrapMeThat(Object *);
        virtual void CloseMe();
};

#endif
