/*
** EPITECH PROJECT, 2020
** ex00
** File description:
** Parser.cpp
*/

#include "Parser.hpp"

Parser::Parser()
{
    _result = 0;
}

void Parser::feed(const std::string & str)
{
    _result += this->calcul(str);
}

int Parser::result() const
{
    return (_result);
}

void Parser::reset()
{
    _result = 0;
}

int Parser::doOperation(int nbr1, int nbr2, char op)
{
    switch(op){
        case '+': return (nbr1 + nbr2);
        case '-': return (nbr1 - nbr2);
        case '*': return (nbr1 * nbr2);
        case '/': return (nbr1 / nbr2);
        case '%': return (nbr1 % nbr2);
        default: return (0);
    }
}

int Parser::precedence(char op)
{
    if(op == '+' || op == '-')
        return (1);
    if(op == '*' || op == '/' || op == '%')
        return (2);
    return (0);
}

int Parser::calcul(std::string str)
{
    std::stack <int> numbers;
    std::stack <char> operators;

    for(unsigned int i = 0; i < str.length(); i++){
        if(str[i] == ' ')
            continue;
        else if(str[i] == '('){
            operators.push(str[i]);
        } else if(isdigit(str[i])){
            int val = 0;
            for (;i < str.length() && isdigit(str[i]); i++)
                val = (val * 10) + (str[i] - '0');
            numbers.push(val);
            i--;
        } else if(str[i] == ')') {
            while(!operators.empty() && operators.top() != '(')
                calculStack(numbers, operators);
            if(!operators.empty())
                operators.pop();
        } else {
            while(!operators.empty() && precedence(operators.top()) >= precedence(str[i]))
                calculStack(numbers, operators);
            operators.push(str[i]);
        }
    }

    while(!operators.empty())
        calculStack(numbers, operators);

    return (numbers.top());
}

void Parser::calculStack(std::stack<int> &numbers, std::stack<char> & operators)
{
    int nbr2 = numbers.top();
    numbers.pop();

    int nbr1 = numbers.top();
    numbers.pop();

    char op = operators.top();
    operators.pop();

    numbers.push(doOperation(nbr1, nbr2, op));
}

//int main()
//{
//    Parser p;
//
//    p.feed("((12*2)+14)");
//    std::cout << p.result() << std::endl;
//    p.feed("((17 % 9) / 4)");
//    std::cout << p.result() << std::endl;
//    p.reset();
//    p.feed("17 - (4 * 13)");
//    std::cout << p.result() << std::endl;
//    p.feed("(((133 / 5) + 6) * ((45642 % 127) - 21))");
//    std::cout << p.result() << std::endl;
//    return (0);
//}