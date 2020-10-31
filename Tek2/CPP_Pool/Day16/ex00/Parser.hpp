/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** Parser.hpp
*/


#ifndef PARSER_H_
#define PARSER_H_

#include <string>
#include <iostream>
#include <stack>


class Parser {
    public:
        Parser();
        ~Parser() = default;
        void feed(const std::string & str);
        int result() const;
        void reset();

    private:
        int _result;
        static int doOperation(int nbr1, int nbr2, char op);
        static int precedence(char op);
        int calcul(std::string str);
        static void calculStack(std::stack <int> & numbers, std::stack <char> & operators);

};


#endif //PARSER_H_
