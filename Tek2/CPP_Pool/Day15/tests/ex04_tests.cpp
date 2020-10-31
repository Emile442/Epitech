/*
** EPITECH PROJECT, 2020
** cpp_d15_2019
** File description:
** ex04_tests
*/

#include <criterion/criterion.h>

#include <string>
#include <ostream>
#include <iostream>

#include "ex04.hpp"

Test(ex04, equal)
{
    int a = 3;
    int b = 9;

    float c = 56.90;
    float d = 830.9403;
    
    double e = 456789876.78909876;
    double f = 564738928478.7548930;

    const std::string g = "Emile le plus beau";
    const std::string h = "Une chaine de reparer";

    cr_assert(::equal(a, a) == 1);
    cr_assert(::equal(a, b) == 0);

    cr_assert(::equal(c, c) == 1);
    cr_assert(::equal(c, d) == 0);

    cr_assert(::equal(e, e) == 1);
    cr_assert(::equal(e, f) == 0);

    cr_assert(::equal(g, g) == 1);
    cr_assert(::equal(g, h) == 0);
}

Test(ex04, equal_it)
{
    Tester<int> iT;
    Tester<float> fL;
    Tester<double> dB;
    Tester<std::string> sT;

    int a = 3;
    int b = 9;

    float c = 56.90;
    float d = 830.9403;
    
    double e = 456789876.78909876;
    double f = 564738928478.7548930;

    const std::string g = "Emile le plus beau";
    const std::string h = "Une chaine de reparer";

    cr_assert(iT.equal(a, a) == 1);
    cr_assert(iT.equal(a, b) == 0);

    cr_assert(fL.equal(c, c) == 1);
    cr_assert(fL.equal(c, d) == 0);

    cr_assert(dB.equal(e, e) == 1);
    cr_assert(dB.equal(e, f) == 0);

    cr_assert(sT.equal(g, g) == 1);
    cr_assert(sT.equal(g, h) == 0);
}