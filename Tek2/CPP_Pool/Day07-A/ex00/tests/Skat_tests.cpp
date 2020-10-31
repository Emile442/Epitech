/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** Skat_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "Skat.hpp"

static void redirectOutputs(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Skat, stimPaks)
{
    Skat s("Junior", 5);
    int tmp = s.stimPaks();
    
    cr_assert(tmp == 5);
}

Test(Skat, name)
{
    Skat s("Junior", 5);
    std::string expected = "Junior";

    cr_assert(s.name() == expected);
}

Test(Skat, shareStimPaks, .init=redirectOutputs)
{
    Skat s("Junior", 5);
    int tmp = 0;
    int jAfter;

    s.shareStimPaks(2, tmp);
    jAfter = s.stimPaks();
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Keep the change.\n");
    cr_assert(tmp == 2);
    cr_assert(jAfter == 3);
}

Test(Skat, shareStimPaksOutOfRange, .init=redirectOutputs)
{
    Skat s("Junior", 5);
    int tmp = 0;

    s.shareStimPaks(200, tmp);
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Don't be greedy\n");
}

Test(Skat, addStimPaks, .init=redirectOutputs)
{
    Skat s("Junior", 5);
    int jAfter;

    s.addStimPaks(3);
    jAfter = s.stimPaks();
    cr_assert(jAfter == 8);
}

Test(Skat, addStimPaksZeroValue, .init=redirectOutputs)
{
    Skat s("Junior", 5);
    int jAfter;

    s.addStimPaks(0);
    jAfter = s.stimPaks();
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Hey boya, did you forget something?\n");
    cr_assert(jAfter == 5);
}

Test(Skat, useStimPaks, .init=redirectOutputs)
{
    Skat s("Junior", 1);
    int jAfter;

    s.useStimPaks();
    jAfter = s.stimPaks();
    cr_assert(jAfter == 0);
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Time to kick some ass and chew bubble gum.\n");
}

Test(Skat, useStimPaksButZero, .init=redirectOutputs)
{
    Skat s("Junior", 0);
    int jAfter;

    s.useStimPaks();
    jAfter = s.stimPaks();
    cr_assert(jAfter == 0);
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Mediiiiiic\n");
}

Test(Skat, status, .init=redirectOutputs)
{
    Skat s("Junior", 5);

    s.status();
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Soldier Junior reporting 5 stimpaks remaining sir!\n");
}