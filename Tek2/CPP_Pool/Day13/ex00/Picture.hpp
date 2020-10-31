/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Picture.hpp
*/


#ifndef PICTURE_H_
#define PICTURE_H_

#include <string>
#include <iostream>
#include <fstream>
#include<sstream>

class Picture {
    public:
        Picture();
        Picture(const std::string & file);
        ~Picture();
        std::string data;
        bool getPictureFromFile (const std::string & file);

    protected:
    private:
};


#endif //PICTURE_H_
