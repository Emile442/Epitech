/*
** EPITECH PROJECT, 2020
** cpp_d06_2019
** File description:
** SickKoala
*/

#include "SickKoala.hpp"

SickKoala::SickKoala(std::string c_name)
{
   name = c_name;
}

SickKoala::~SickKoala()
{
   std::cout << "Mr."<< this->name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

void SickKoala::poke()
{
   std::cout << "Mr."<< this->name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string str)
{
   if (str.compare("Mars") == 0) {
      std::cout << "Mr."<< this->name << ": Mars, and it kreogs!" << std::endl;
      return (true);
   } else if (str.compare("Buronzand") == 0) {
      std::cout << "Mr."<< this->name << ": And you'll sleep right away!" << std::endl;
      return (true);
   }
   std::cout << "Mr."<< this->name << ": Goerkreog!" << std::endl;
   return (false);
}

void SickKoala::overDrive(std::string str)
{
   std::string toFind = "Kreog!";
   std::string toReplace = "1337!";
   std::size_t pos = str.find("Kreog!");

   while (pos != std::string::npos) {
      str.replace(pos, toFind.size(), toReplace);
      pos = str.find(toFind, pos + toReplace.size());
   }
   std::cout << "Mr."<< this->name << ": " << str << std::endl;
}

std::string SickKoala::getName()
{
   return (this->name);
}