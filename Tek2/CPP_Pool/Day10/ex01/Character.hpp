/*
** EPITECH PROJECT, 2020
** cpp_d10_2019
** File description:
** Character.hpp
*/


#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include <iostream>

#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character {
    public:
        Character(const std::string &name);
        ~Character();
        void recoverAP();
        void equip(AWeapon* weapon);
        void attack(AEnemy* enemy);
        std::string const & getName() const;
        int getAp() const;
        AWeapon* getWeapon() const;
        void removeAp(int nbr);

    private:
        std::string _name;
        int _ap;
        AWeapon* _weapon;

};

std::ostream & operator<<(std::ostream&, Character const &ref);

#endif //CPP_D10_2019_CHARACTER_HPP
