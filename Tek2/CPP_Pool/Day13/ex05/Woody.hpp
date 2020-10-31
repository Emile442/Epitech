/*
** EPITECH PROJECT, 2020
** ex02
** File description:
** Woody.hpp
*/


#ifndef WOODY_H_
#define WOODY_H_

#include <string>
#include <iostream>
#include "Toy.hpp"

class Woody : public Toy {
    public:
        Woody(const std::string & name, const std::string & filename = "woody.txt");
        ~Woody();
        void speak(std::string const & str);
    private:
};


#endif //WOODY_H_
