/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Warrior
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include <string>
#include <iostream>

#include "Character.hpp"

class Warrior : public Character {
	public:
        Warrior(const std::string &name, int level);
		~Warrior();
		int CloseAttack();
		int RangeAttack();

	private:
        std::string _weaponName;
};

#endif /* !WARRIOR_HPP_ */
