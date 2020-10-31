/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** SickKoala
*/

#ifndef SickKoala_H
#define SickKoala_H

#include <string>
#include <iostream>
#include <algorithm>

class SickKoala {
	public:
		SickKoala(std::string);
		~SickKoala();
		void poke();
		bool takeDrug(std::string);
		void overDrive(std::string);
		std::string getName();
		
	private:
        std::string name;
};

#endif /* !SickKoala */
