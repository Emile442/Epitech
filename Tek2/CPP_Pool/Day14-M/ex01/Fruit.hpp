/*
** EPITECH PROJECT, 2020
** cpp_d14m_2019
** File description:
** Fruit.hpp
*/


#ifndef FRUIT_H_
#define FRUIT_H_

#include <string>
#include <iostream>

class Fruit {
    public:
        Fruit(const std::string & name, int vitamins);
        virtual ~Fruit();
        virtual std::string getName() const;
        void setName(const std::string &name);
        int getVitamins() const;
        void setVitamins(int vitamin);

    protected:
        std::string _name;
        int _vitamins;
};


#endif //FRUIT_H_
