/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** FruitBox.cpp
*/

#include "FruitBox.hpp"

FruitBox::FruitBox(int size) : _size(size), _nbrFruit(0), _box(nullptr)
{

}

FruitBox::~FruitBox()
{

}

int FruitBox::nbFruits()
{
    return (_nbrFruit);
}

/**
 * Put Fruit to the end of the list
 * @param Fruit* f
 * @return nullptr | (true|false)
 */
bool FruitBox::putFruit(Fruit *f)
{
    if (!f || _nbrFruit >= _size)
        return (false);
    if (checkAlready(f))
        return (false);
    reverse();
    push(f);
    reverse();
    _nbrFruit++;
    return (true);
}

/**
 * Remove the first fruit
 * @return nullptr | Fruit*
 */
Fruit *FruitBox::pickFruit()
{
    if (!_box)
        return (nullptr);
    Fruit* rt = _box->_fruit;
    pull();
    _nbrFruit--;
    return (rt);
}

/**
 * Return Box
 * @return
 */
FruitNode *FruitBox::head()
{
    return (_box ? _box : nullptr);
}

void FruitBox::reverse()
{
    FruitNode* current = _box;
    FruitNode *prev = nullptr, *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    _box = prev;
}

void FruitBox::push(Fruit *f)
{
    auto* newNode = new FruitNode();

    newNode->_fruit = f;
    newNode->next = _box;
    _box = newNode;
}

void FruitBox::pull()
{
    if (_box)
        _box = _box->next;
}

bool FruitBox::checkAlready(Fruit *f)
{
    FruitNode* current = _box;
    while(current != nullptr) {
        if (current->_fruit == f)
            return (true);
        current = current->next;
    }

    return (false);
}


