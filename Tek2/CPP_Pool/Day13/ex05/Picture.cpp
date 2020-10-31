/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Picture.cpp
*/

#include "Picture.hpp"

Picture::Picture() : data("")
{
}

Picture::Picture(const std::string & file)
{
    getPictureFromFile(file);
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
    std::ifstream f;
    std::string content;
    char c;

    f.open(file, std::ios::in);
    if (!f) {
        this->data = "ERROR";
        return (false);
    }

    while (f.good()) {
        c = f.get();
        if (c != -1)
            content += c;
    }
    f.close();

    this->data = content;
    return (true);
}

Picture &Picture::operator=(Picture const &ref)
{
    this->data = ref.data;
    return (*this);
}

