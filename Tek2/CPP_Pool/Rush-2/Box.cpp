/*
** EPITECH PROJECT, 2022
** Tek2
** File description:
** Created by Zebens,
*/

#include "Box.hpp"

Box::Box(const std::string &Title)
: Wrap(), Object(Title)
{
}

Box::~Box()
{
}

void Box::CloseMe()
{
    _isOpen = false;
}

bool Box::BoxIsOpen()
{
    return _isOpen;
}

bool Box::WrapMeThat(Object* object)
{
    if (!GetIsOpen())
        return false;
    return (Wrap::wrapMeThat(object));
}