/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** Parts_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Parts.hpp"

// std::cout << std::flush;
// cr_assert_stdout_eq_str("\n");
static void redirectOutputs(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Arms, isFunctionnal)
{
    Arms tmp;

    cr_assert(tmp.isFunctionnal() == true);
}

Test(Arms, serial)
{
    Arms tmp;
    std::string expected = "A-01";

    cr_assert(tmp.serial() == expected);
}

Test(Arms, informations, .init=redirectOutputs)
{
    Arms tmp;

    tmp.informations();
    std::cout << std::flush;
    cr_assert_stdout_eq_str("\t[Parts] Arms A-01 status : OK\n");
}

Test(Legs, isFunctionnal)
{
    Legs tmp;

    cr_assert(tmp.isFunctionnal() == true);
}

Test(Legs, serial)
{
    Legs tmp;
    std::string expected = "L-01";

    cr_assert(tmp.serial() == expected);
}

Test(Legs, informations, .init=redirectOutputs)
{
    Legs tmp;

    tmp.informations();
    std::cout << std::flush;
    cr_assert_stdout_eq_str("\t[Parts] Legs L-01 status : OK\n");
}

Test(Head, isFunctionnal)
{
    Head tmp;

    cr_assert(tmp.isFunctionnal() == true);
}

Test(Head, serial)
{
    Head tmp;
    std::string expected = "H-01";

    cr_assert(tmp.serial() == expected);
}

Test(Head, informations, .init=redirectOutputs)
{
    Head tmp;

    tmp.informations();
    std::cout << std::flush;
    cr_assert_stdout_eq_str("\t[Parts] Head H-01 status : OK\n");
}