/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** OneTime
*/

#ifndef ONETIME_HPP_
#define ONETIME_HPP_

#include <iostream>
#include <string>

#include "IEncryptionMethod.hpp"

class OneTime: public IEncryptionMethod {
	public:
		OneTime(const std::string & key);
		~OneTime();
        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
        void reset();

	private:
        char upLetter(char c, bool crypt);
        std::string _key;
        int _round;
};

#endif /* !ONETIME_HPP_ */
