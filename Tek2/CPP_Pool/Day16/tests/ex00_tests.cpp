/*
** EPITECH PROJECT, 2020
** cpp_d09_2019
** File description:
** ex00_tests
*/

#include <criterion/criterion.h>

#include <string>
#include <ostream>
#include <iostream>

#include "Parser.hpp"

Test(Parser, feed_simple) {
    Parser p;

    p.feed("2 + 2");
    cr_assert(p.result() == 4);
}

Test(Parser, feed_parenthese) {
    Parser p;

    p.feed("(2 + 2) * 4");
    cr_assert(p.result() == 16);
}

Test(Parser, feed_multiple_parenthese) {
    Parser p;

    p.feed("(2 * 2 * (4 / 2)) * 4");
    cr_assert(p.result() == 32);
}

Test(Parser, feed_all_op) {
    Parser p;

    p.feed("((2 - 2 * (4 / 2)) * 4 + 3) % 10");
    cr_assert(p.result() == -5);
}

Test(Parser, feed_reset) {
    Parser p;

    p.feed("((2 - 2 * (4 / 2)) * 4 + 3) % 10");
    cr_assert(p.result() == -5);
    p.reset();
    cr_assert(p.result() == 0);
}

Test(Parser, feed_non_reset) {
    Parser p;

    p.feed("((2 - 2 * (4 / 2)) * 4 + 3) % 10");
    cr_assert(p.result() == -5);
    p.feed("5 + 5");
    cr_assert(p.result() == 5);
}

Test(Parser, exemple) {
    Parser p;

    p.feed("((12*2)+14)");
    cr_assert(p.result() == 38);
    p.feed("((17 % 9) / 4)");
    cr_assert(p.result() == 40);
    p.reset();
    p.feed("17 - (4 * 13)");
    cr_assert(p.result() == -35);
    p.feed("(((133 / 5) + 6) * ((45642 % 127) - 21))");
    cr_assert(p.result() == 861);
}