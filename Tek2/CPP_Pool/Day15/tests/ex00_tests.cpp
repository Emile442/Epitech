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

#include "ex00.hpp"

Test(ex00, swap) {
    int a = 3;
    int b = 9;

    ::swap(a, b);

    cr_assert(a == 9);
    cr_assert(b == 3);   
}

Test(ex00, min) {
    int a = 3;
    int b = 9;

    cr_assert(::min(a, b) == 3);
}

Test(ex00, max) {
    int a = 3;
    int b = 9;

    cr_assert(::max(a, b) == 9);
}

Test(ex00, swap_str) {
    std::string a = "chaine1";
    std::string b = "chaine2";

    ::swap(a, b);

    cr_assert(a == "chaine2");
    cr_assert(b == "chaine1"); 
}

Test(ex00, min_str) {
    std::string a = "chaine1";
    std::string b = "chaine2";

    cr_assert(::min(a, b) == "chaine1");
}

Test(ex00, max_str) {
    std::string a = "chaine1";
    std::string b = "chaine2";

    cr_assert(::max(a, b) == "chaine2");
}