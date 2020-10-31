/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** KoalaNurse
*/

#include "SickKoala.hpp"
#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int k_id)
{
    id = k_id;
    working = false;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << this->id <<": Finally some rest!" << std::endl;
    this->id = 0;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala* koala)
{
    if (koala)
        koala->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::string koalaName = filename;
    std::string nameExt = ".report";
    std::size_t posExt = filename.find(nameExt);
    std::ifstream file;
    std::string drug;
    
    file.open(filename, std::ios::in);
    if (!file.is_open())
        return ("");
    koalaName.replace(posExt, nameExt.size(), "");
    std::getline(file, drug);
    std::cout << "Nurse " << this->id << ": Kreog! Mr." << koalaName << " needs a " << drug << "!" << std::endl;
    return (drug);
}


void KoalaNurse::timeCheck()
{
    if (!this->working)
        std::cout << "Nurse " << this->id << ": Time to get to work!" << std::endl;
    else
        std::cout << "Nurse " << this->id << ": Time to go home to my eucalyptus forest!" << std::endl;
    this->working = !this->working;
}