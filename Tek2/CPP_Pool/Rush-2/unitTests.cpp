/*
** EPITECH PROJECT, 2020
** cpp_rush2_2019
** File description:
** unitTests.cpp
*/

#include "unitTests.hpp"

Object **MyUnitTests()
{
    Object** obj = new Object*[2];

    obj[0] = new LittlePony("happy pony");
    obj[1] = new Teddy("cuddles");
    return (obj);
}


Object *MyUnitTests(Object **objects)
{
    if (!objects[1]->isOpen())
        objects[1]->open();
    objects[1]->WrapMeThat(objects[0]);
    objects[2]->WrapMeThat(objects[1]);
    return (objects[2]);
}