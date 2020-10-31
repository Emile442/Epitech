/*
** EPITECH PROJECT, 2020
** ex01
** File description:
** LittleHand.hpp
*/


#ifndef LITTLEHAND_H_
#define LITTLEHAND_H_

#include "FruitBox.hpp"
#include "FruitNode.hpp"
#include "Banana.hpp"
#include "Lemon.hpp"
#include "Lime.hpp"

class LittleHand {
    public:
        LittleHand();
        ~LittleHand();
        static void sortFruitBox(FruitBox &unsorted , FruitBox &lemons , FruitBox &bananas , FruitBox & limes);

    protected:
    private:
};


#endif //LITTLEHAND_H_
