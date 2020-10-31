//
// Created by aguichet on 1/25/20.
//

#ifndef CPP_RUSH2_2019_CONVEYORBELT_HPP
#define CPP_RUSH2_2019_CONVEYORBELT_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Object.hpp"
#include "Wrap.hpp"

class ConveyorBelt {
    public:
        ConveyorBelt();
        ~ConveyorBelt();
        bool GetisCharge() const;
        void INButton(Wrap *Wrap);
        Wrap *OUTButton();
        Object *_Object;
        bool _isCharge;
    protected:
        Wrap *_Wrap;
};



#endif //CPP_RUSH2_2019_CONVEYORBELT_HPP
