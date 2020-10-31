/*
** EPITECH PROJECT, 2020
** ex02
** File description:
** Buzz.hpp
*/


#ifndef BUZZ_H_
#define BUZZ_H_

#include <string>
#include <iostream>
#include "Toy.hpp"

class Buzz: public Toy {
    public:
        Buzz(const std::string & name, const std::string & filename = "buzz.txt");
        ~Buzz();
        void speak(std::string const & str);
        bool speak_es(std::string const & str);

    protected:
    private:
};


#endif //BUZZ_H_
