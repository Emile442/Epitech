/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaDoctor
*/

#ifndef KOALADOCTOR_HPP_
#define KOALADOCTOR_HPP_

#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

#include "SickKoala.hpp"


class KoalaDoctor {
	public:
		KoalaDoctor(std::string);
		~KoalaDoctor();
        void diagnose(SickKoala*);
        void timeCheck();

	private:
        std::string name;
        bool working;
};

#endif /* !KOALADOCTOR_HPP_ */
