/*
** EPITECH PROJECT, 2020
** cpp_d13_2019
** File description:
** Toy.hpp
*/


#ifndef TOY_H_
#define TOY_H_

#include <string>
#include <iostream>
#include "Picture.hpp"

class Toy {
    public:
        Toy();
        ~Toy();
        enum ToyType {BASIC_TOY, ALIEN, BUZZ, WOODY};
        ToyType getType() const;
        std::string getName() const;
        void setName(const std::string & name);
        bool setAscii(const std::string & filename);
        std::string getAscii() const;
        Toy(ToyType toyType, const std::string & name, const std::string & filename);
        Toy(Toy const & ref);
        Toy& operator=(Toy const & ref);
        virtual void speak(std::string const & str);
        virtual bool speak_es(std::string const & str);
        Toy& operator<<(std::string const & str);

        class Error {
            public:
                enum ErrorType {UNKNOWN, PICTURE, SPEAK};
                Error(ErrorType errorType = ErrorType::UNKNOWN);
                ~Error();
                std::string what() const;
                std::string where() const;
                void setType(ErrorType typeErr);
            public:
                ErrorType type;
        };
        Error getLastError() const;

    private:
        ToyType _type;
        std::string _name;
        Picture _picture;
        Error _error;
};

std::ostream & operator<<(std::ostream & os, Toy const & ref);

#endif //TOY_H_
