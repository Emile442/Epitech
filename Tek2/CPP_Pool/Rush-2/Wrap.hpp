//
// Created by aguichet on 1/25/20.
//

#ifndef CPP_RUSH2_2019_WRAP_HPP
#define CPP_RUSH2_2019_WRAP_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Object.hpp"

class Wrap {
    protected:
    bool _isOpen;
    Object* _content;

    public:
    Wrap();
    virtual ~Wrap();
    virtual bool wrapMeThat(Object *object);
    virtual void openMe();
    virtual void closeMe();
    bool GetIsOpen() const;
    Object *accessObject();
};



#endif
