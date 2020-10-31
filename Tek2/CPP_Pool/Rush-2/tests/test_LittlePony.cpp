/*
** EPITECH PROJECT, 2018
** cpp_d07m_2019
** File description:
** Created by Tornike,
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../LittlePony.hpp"
#include "OSRedirection.hpp"

static void redirect_all_std(void) {
    cr_redirect_stdout();
    cr_redirect_stderr();
};

Test(LittlePony, LittlePony_is_taken, .init = redirect_all_std) {
    Toy t("title");
    LittlePony lp("Name test");
    OSRedirector oss(std::cout);

    lp.isTaken();
    cr_assert_eq("yo man\n", oss.getContent());
}