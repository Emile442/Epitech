/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string d_name)
{
    name = d_name;
    working = false;
    std::cout << "Dr." << d_name << ": I'm Dr." << d_name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala* patient)
{
    std::string reportName = patient->getName() + ".report";
    std::string drugs[] = {
        "Mars",
        "Buronzand",
        "Viagra",
        "Extasy",
        "Eucalyptus leaf"
    };

    std::cout << "Dr." << this->name << ": So what's goerking you Mr." << patient->getName() << "?" << std::endl;
    patient->poke();

    std::fstream reportFile;
    reportFile.open(reportName, std::fstream::out | std::fstream::trunc);
    if (!reportFile.is_open())
        return;
    reportFile << drugs[random() % 5] << std::endl;
}

void KoalaDoctor::timeCheck()
{
    if (!this->working)
        std::cout << "Dr." << this->name << ": Time to get to work!" << std::endl;
    else
        std::cout << "Dr." << this->name << ": Time to go home to my eucalyptus forest!" << std::endl;
    this->working = !this->working;
}
