/*
** EPITECH PROJECT, 2019
** stock bits
** File description:
** stocks 6 bits and gives them back after 6 calls
*/

#include "../include/navy.h"

int stock_bits(bool get, bool bit)
{
    static char bits[6];
    static int calls = 0;

    if (get) {
        if (calls < 6)
            return (-1);
        calls = 0;
        return (10*(bits[0]*4+bits[1]*2+bits[2])+bits[3]*4+bits[4]*2+bits[5]);
    }
    if (calls < 6) {
        bits[calls] = bit;
        calls++;
    }
    return (0);
}
