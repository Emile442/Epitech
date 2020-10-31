/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaNurse
*/

#ifndef KoalaNurse_H
#define KoalaNurse_H

#include <string>
#include <iostream>
#include <fstream>

#include "SickKoala.hpp"

class KoalaNurse {
	public:
		KoalaNurse(int);
		~KoalaNurse();
        void giveDrug(std::string, SickKoala*);
        std::string readReport(std::string);
		void timeCheck();

	private:
        int id;
		bool working;
};

#endif /* !KoalaNurse */
