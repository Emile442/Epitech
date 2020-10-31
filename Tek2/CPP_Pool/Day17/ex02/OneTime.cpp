/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** OneTime
*/

#include "OneTime.hpp"

OneTime::OneTime(const std::string & key) : _key(key), _round(0)
{
}

OneTime::~OneTime()
{
}

char OneTime::upLetter(char c, bool crypt)
{
    if (isalpha(c)) {
        int minMaj = crypt ? (c > 96 ? 97 : 65) : (c > 96 ? 122 : 90);
        int bMinMaj = _key[_round] > 96 ? 97 : 65;
        if (crypt)
            c = (c - minMaj + (_key[_round] - bMinMaj)) % 26 + minMaj;
        else
            c = (c - minMaj - (_key[_round] - bMinMaj)) % 26 + minMaj;
    }
    _round = (_round + 1) % _key.size();
    return (c);
}

void OneTime::encryptChar(char plainchar)
{
    std::cout << upLetter(plainchar, true);
}

void OneTime::decryptChar(char cipherchar)
{
    std::cout << upLetter(cipherchar, false);
}

void OneTime::reset()
{
    this->_round = 0;
}
