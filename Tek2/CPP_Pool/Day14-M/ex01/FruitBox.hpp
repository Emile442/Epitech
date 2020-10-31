/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** FruitBox.hpp
*/


#ifndef FRUITBOX_H_
#define FRUITBOX_H_

#include <string>
#include <iostream>
#include "FruitNode.hpp"

class FruitBox {
    public:
        FruitBox(int size);
        ~FruitBox();
        int nbFruits() const;
        bool putFruit(Fruit* f);
        Fruit *pickFruit();
        FruitNode *head() const;

    private:
        int _size;
        int _nbrFruit;
        FruitNode* _box;
        void reverse();
        void push(Fruit* f);
        bool checkAlready(Fruit* f);
        void pull();
};


#endif //FRUITBOX_H_
