/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** Siclkoala_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "SickKoala.hpp"

static void redirectOutputs(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(koala, delete, .init=redirectOutputs)
{
    SickKoala* koala = new SickKoala("emile");

    delete koala;
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Mr.emile: Kreooogg!! I'm cuuuured!\n");
}

Test(koala, poke, .init=redirectOutputs)
{
    SickKoala* koala = new SickKoala("emile");
    
    koala->poke();
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Mr.emile: Gooeeeeerrk!!\n");
}

Test(koala, takeDrugMars, .init=redirectOutputs)
{
    SickKoala* koala = new SickKoala("emile");
    
    koala->takeDrug("Mars");
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Mr.emile: Mars, and it kreogs!\n");
}

Test(koala, takeDrugBuronzand, .init=redirectOutputs)
{
    SickKoala* koala = new SickKoala("emile");
    
    koala->takeDrug("Buronzand");
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Mr.emile: And you'll sleep right away!\n");
}

Test(koala, takeDrugOther, .init=redirectOutputs)
{
    SickKoala* koala = new SickKoala("emile");
    
    koala->takeDrug("hoiuuoeh");
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Mr.emile: Goerkreog!\n");
}

Test(koala, overDrive, .init=redirectOutputs)
{
    SickKoala* koala = new SickKoala("emile");
    
    koala->overDrive("Kreog! vient ici !");
    std::cout << std::flush;
    cr_assert_stdout_eq_str("Mr.emile: 1337! vient ici !\n");
}
