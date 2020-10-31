/*
** EPITECH PROJECT, 2020
** ex01
** File description:
** LittleHand.cpp
*/

#include "LittleHand.hpp"

LittleHand::LittleHand()
{

}

LittleHand::~LittleHand()
{

}

void LittleHand::sortFruitBox(FruitBox &unsorted, FruitBox &lemons, FruitBox &bananas, FruitBox &limes)
{
    auto *noList = new FruitBox(unsorted.nbFruits());

    for (Fruit *fruit = unsorted.pickFruit(); fruit != nullptr; fruit = unsorted.pickFruit()) {
        if (dynamic_cast<Banana*>(fruit)) {
            if (!bananas.putFruit(fruit))
                noList->putFruit(fruit);
            continue;
        }
        if (dynamic_cast<Lime*>(fruit)) {
            if (!limes.putFruit(fruit))
                noList->putFruit(fruit);
            continue;
        }
        if (dynamic_cast<Lemon*>(fruit)) {
            if (!lemons.putFruit(fruit))
                noList->putFruit(fruit);
            continue;
        }
        noList->putFruit(fruit);
    }

    for (Fruit *fruit = noList->pickFruit(); fruit != nullptr; fruit = noList->pickFruit())
        unsorted.putFruit(fruit);
}
