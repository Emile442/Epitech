/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <iostream>

class Character {
	public:
		Character(const std::string &name, int level);
        const std::string & getName() const;
        ~Character();
        int getLvl() const;
        int getPv() const;
        int getPower() const;
        virtual int	CloseAttack();
        virtual int RangeAttack();

        virtual void Heal();

        virtual void RestorePower();
        void TakeDamage(int damage);
        enum AttackRange {CLOSE, RANGE};
        AttackRange Range;

    protected:
        bool canAttack(int required);
        std::string _name;
        int	_strength;
        int	_stamina;
        int	_intelligence;
        int _spirit;
        int _agility;
        int	_power;
        int	_pv;

    private:
        int	_level;
};

#endif /* !CHARACTER_HPP_ */
