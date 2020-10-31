/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** FruitNode.hpp
*/


#ifndef FRUITNODE_H_
#define FRUITNODE_H_

#include <string>
#include <iostream>

#include "Fruit.hpp"

struct FruitNode {
    Fruit* _fruit;
    FruitNode* next;
};

#endif //FRUITNODE_H_
