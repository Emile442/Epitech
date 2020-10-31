/*
** EPITECH PROJECT, 2020
** cpp_d08_2019
** File description:
** Droid
*/

#ifndef DROID_HPP_
#define DROID_HPP_

#include <string>
#include <iostream>

#include "DroidMemory.hpp"

class Droid {
	public:
		Droid(std::string serial, size_t energy = 50, const size_t attack = 25, const size_t toughness = 15, std::string* status = new std::string("Standing by"));
        Droid(const Droid &ref);
        Droid &operator=(const Droid &ref);
		~Droid();

        std::string getId() const;
        void setId(std::string serial);
        size_t getEnergy() const;
        void setEnergy(size_t energy);
        size_t getAttack() const;
        size_t getToughness() const;
        std::string &getStatus() const;
        void setStatus(std::string* serial);

        bool operator==(const Droid &ref) const;
        bool operator!=(const Droid &ref) const;
        Droid& operator<<(size_t &);

        DroidMemory* getBattleData() const;
        void setBattleData(DroidMemory* battleData);

        bool operator()(std::string const * task, size_t exp);

	private:
        std::string _serial;
        size_t _energy;
        const size_t _attack;
        const size_t _toughness;
        std::string* _status;
        DroidMemory* _battleData;
};

std::ostream & operator<<(std::ostream&, Droid const &ref);

#endif /* !DROID_HPP_ */
