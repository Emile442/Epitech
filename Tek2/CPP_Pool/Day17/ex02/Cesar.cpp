/*
** EPITECH PROJECT, 2020
** cpp_d17_2019
** File description:
** Cesar
*/

#include "Cesar.hpp"

Cesar::Cesar() : _round(3)
{
}

Cesar::~Cesar()
{
}

char Cesar::upLetter(char c, bool crypt)
{
    if (isalpha(c)) {
        int minMaj = crypt ? (c > 96 ? 97 : 65) : (c > 96 ? 122 : 90);
        if (crypt)
            c = (c - minMaj + _round) % 26 + minMaj;
        else
            c = (c - minMaj - _round) % 26 + minMaj;
    }
    _round = (_round + 1) % 26;
    return (c);
}

void Cesar::encryptChar(char plainchar)
{
    std::cout << upLetter(plainchar, true);
}

void Cesar::decryptChar(char cipherchar)
{
    std::cout << upLetter(cipherchar, false);
}

void Cesar::reset()
{
    this->_round = 3;
}

// static void encryptString(IEncryptionMethod& encryptionMethod , std::string const& toEncrypt) {
//     size_t len = toEncrypt.size();
    
//     encryptionMethod.reset();
//     for (size_t i = 0; i < len; ++i)
//         encryptionMethod.encryptChar(toEncrypt[i]); 
//     std::cout << std::endl;
// }

// static void decryptString(IEncryptionMethod& encryptionMethod , std::string const& toDecrypt) {
//     size_t len = toDecrypt.size();

//     encryptionMethod.reset();
//     for (size_t i = 0; i < len; ++i)
//         encryptionMethod.decryptChar(toDecrypt[i]); 
//     std::cout << std::endl;
// }

// int main()
// {
//     Cesar c;
//     encryptString(c, "Je clair Luc, ne pas ? Ze woudrai un kekos !");
//     decryptString(c, "Mi isirb Xhq, ew jvo ? Zf zszjyir fz ytafk !");
//     encryptString(c, "KIKOO");
//     encryptString(c, "LULZ XD");
//     decryptString(c, "Ziqivun ea Ndcsg.Wji !");
//     return 0;
// }
