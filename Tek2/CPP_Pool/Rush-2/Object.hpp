/*
** EPITECH PROJECT, 2022
** Object.hpp
** File description:
** Created Zebens,
*/

#ifndef _OBJECT_HPP_
#define _OBJECT_HPP_

#include <string>
#include <iostream>

class Object {
    public:
        Object(const std::string &);
        virtual ~Object();
        const std::string &getTitle();
    protected:
        const std::string _title;
};

#endif