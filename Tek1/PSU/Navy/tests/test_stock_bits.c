/*
** EPITECH PROJECT, 2019
** test
** File description:
** test stock bits
*/

#include "../include/navy.h"
#include <criterion/criterion.h>

Test(stock_bits, basic_test)
{
    for (int i = 0; i < 6; i++)
        stock_bits(false, 1);
    cr_assert(stock_bits(true, 0) == 77);
}

Test(stock_bits, call_with_not_enough_bits)
{
    for (int i = 0; i < 4; i++)
        stock_bits(false, 1);
    cr_assert(stock_bits(true, 0) == -1);
}

Test(stock_bits, basic_test_2)
{
    stock_bits(false, 1);
    stock_bits(false, 1);
    stock_bits(false, 0);
    stock_bits(false, 0);
    stock_bits(false, 0);
    stock_bits(false, 1);
    cr_assert(stock_bits(true, 0) == 61);
}
