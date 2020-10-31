/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** KreogCom
*/

#ifndef KREOGCOM_HPP_
#define KREOGCOM_HPP_

#include <string>
#include <iostream>

class KreogCom {
    public:
        KreogCom(int x, int y, int serial);
        ~KreogCom();
        void addCom(int x, int y, int serial);
        void removeCom();
        KreogCom *getCom();
        void ping() const;
        void locateSquad() const;

    private:
        int _x;
        int _y;
        const int _serial;
        KreogCom* next;
};

#endif /* !KREOGCOM_HPP_ */
