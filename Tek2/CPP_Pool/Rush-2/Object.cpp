/*
** EPITECH PROJECT, 2022
** Tek2
** File description:
** Created by Zebens,
*/

#include "Object.hpp"

Object::Object(const std::string &title) : _title(title)
{
}

Object::~Object()
{
}

const std::string &Object::getTitle()
{
    return (_title);
}
