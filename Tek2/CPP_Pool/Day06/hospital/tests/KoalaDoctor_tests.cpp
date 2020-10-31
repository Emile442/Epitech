/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaDoctor_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "SickKoala.hpp"
#include "KoalaNurse.hpp"
#include "KoalaDoctor.hpp"

static void redirectOutputs(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(doctor, new, .init=redirectOutputs)
{
    KoalaDoctor* doctor = new KoalaDoctor("Julien");

    std::cout << std::flush;
    cr_assert_stdout_eq_str("Dr.Julien: I'm Dr.Julien! How do you kreog?\n");
    delete doctor;
}

Test(doctor, diagnose, .init=redirectOutputs)
{
    KoalaDoctor* doctor = new KoalaDoctor("Julien");
    SickKoala* patient = new SickKoala("paul");

    doctor->diagnose(patient);
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Dr.Julien: I'm Dr.Julien! How do you kreog?\nDr.Julien: So what's goerking you Mr.paul?\nMr.paul: Gooeeeeerrk!!\n");
}

Test(doctor, timeCheckWork, .init=redirectOutputs)
{
    KoalaDoctor* doctor = new KoalaDoctor("Julien");

    doctor->timeCheck();
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Dr.Julien: I'm Dr.Julien! How do you kreog?\nDr.Julien: Time to get to work!\n");
}

Test(doctor, timeCheckNotWork, .init=redirectOutputs)
{
    KoalaDoctor* doctor = new KoalaDoctor("Julien");

    doctor->timeCheck();
    doctor->timeCheck();
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Dr.Julien: I'm Dr.Julien! How do you kreog?\nDr.Julien: Time to get to work!\nDr.Julien: Time to go home to my eucalyptus forest!\n");
}
