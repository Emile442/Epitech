/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** AEnemy.hpp
*/


#ifndef AENEMY_H_
#define AENEMY_H_

#include <string>
#include <iostream>

class AEnemy {
    public:
        AEnemy(int hp, const std::string &type);

        virtual ~AEnemy();

        virtual void takeDamage(int damage);
        std::string	const & getType() const;
        int getHP() const;

    protected:
        int _hp;
        std::string _type;
};

#endif //CPP_D10_2019_AENEMY_HPP
