/*
** EPITECH PROJECT, 2020
** cpp_d07a_2019
** File description:
** Parts_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "KoalaBot.hpp"

// std::cout << std::flush;
// cr_assert_stdout_eq_str("\n");
static void redirectOutputs(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(KoalaBot, setParts, .init=redirectOutputs)
{
    KoalaBot kb;
    Arms* gun = new Arms("Gun");
    Legs* jean = new Legs("Jean");
    Head *casque = new Head("Casque");

    kb.setParts(*jean);
    kb.setParts(*gun);
    kb.setParts(*casque);
    kb.informations();
    std::cout << std::flush;
    cr_assert_stdout_eq_str("[KoalaBot] Bob-01\n\t[Parts] Arms Gun status : OK\n\t[Parts] Legs Jean status : OK\n\t[Parts] Head Casque status : OK\n");
}

Test(KoalaBot, swapParts, .init=redirectOutputs)
{
    KoalaBot kb;
    Arms* gun = new Arms("Gun");
    Legs* jean = new Legs("Jean");
    Head *casque = new Head("Casque");

    Arms* gun2 = new Arms("Bubble");
    Legs* jean2 = new Legs("Skin", false);
    Head *casque2 = new Head("Corn", false);

    kb.setParts(*jean);
    kb.setParts(*gun);
    kb.setParts(*casque);

    kb.swapParts(*gun2);
    kb.swapParts(*jean2);
    kb.swapParts(*casque2);

    kb.informations();

    std::cout << std::flush;
    cr_assert_stdout_eq_str("[KoalaBot] Bob-01\n\t[Parts] Arms Bubble status : OK\n\t[Parts] Legs Skin status : KO\n\t[Parts] Head Corn status : KO\n");
}

Test(KoalaBot, status, .init=redirectOutputs)
{
    KoalaBot kb;
    Arms* gun = new Arms("Gun");
    Legs* jean = new Legs("Jean");
    Head *casque = new Head("Casque");
    Head *casque2 = new Head("Corn", false);

    kb.setParts(*jean);
    kb.setParts(*gun);
    kb.setParts(*casque);
    cr_assert(kb.status() == true);

    kb.swapParts(*casque2);
    cr_assert(kb.status() == false);
}

Test(KoalaBot, informations, .init=redirectOutputs)
{
    KoalaBot kb;

    kb.informations();
    std::cout << std::flush;
    cr_assert_stdout_eq_str("[KoalaBot] Bob-01\n\t[Parts] Arms A-01 status : OK\n\t[Parts] Legs L-01 status : OK\n\t[Parts] Head H-01 status : OK\n");
}