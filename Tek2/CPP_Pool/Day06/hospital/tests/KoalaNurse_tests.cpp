/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaNurse
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "SickKoala.hpp"
#include "KoalaNurse.hpp"

static void redirectOutputs(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(nurse, delete, .init=redirectOutputs)
{
    KoalaNurse* nurse = new KoalaNurse(33);

    delete nurse;
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Nurse 33: Finally some rest!\n");
}

Test(nurse, giveDrug, .init=redirectOutputs)
{
    KoalaNurse* nurse = new KoalaNurse(33);
    SickKoala* koala = new SickKoala("emile");

    nurse->giveDrug("Mars", koala);
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Mr.emile: Mars, and it kreogs!\n");
}

Test(nurse, readReport, .init=redirectOutputs)
{
    KoalaNurse* nurse = new KoalaNurse(33);

    nurse->readReport("hospital/tests/emile.report");
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Nurse 33: Kreog! Mr.hospital/tests/emile needs a Mars!\n");
}

Test(nurse, readReportFail, .init=redirectOutputs)
{
    KoalaNurse* nurse = new KoalaNurse(33);
    std::string tmp;

    tmp = nurse->readReport("hospital/tests/emiless.report");
    std::cout << std::flush;
    cr_assert_str_eq(tmp.c_str(), "");
}

Test(nurse, timeCheckWork, .init=redirectOutputs)
{
    KoalaNurse* nurse = new KoalaNurse(33);

    nurse->timeCheck();
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Nurse 33: Time to get to work!\n");
}

Test(nurse, timeCheckNotWork, .init=redirectOutputs)
{
    KoalaNurse* nurse = new KoalaNurse(33);

    nurse->timeCheck();
    nurse->timeCheck();
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Nurse 33: Time to get to work!\nNurse 33: Time to go home to my eucalyptus forest!\n");
}