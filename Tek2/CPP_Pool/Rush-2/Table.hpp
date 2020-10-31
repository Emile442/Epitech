//
// Created by aguichet on 1/25/20.
//

#ifndef CPP_RUSH2_2019_TABLE_HPP
#define CPP_RUSH2_2019_TABLE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Object.hpp"

class Table {
    public:
        Table();
        ~Table();
        int GetNbObjects();
        bool GetIsCollapse() const;
        Object **_Object;
    private:
        int _NbObjects;
        bool _IsCollapse;
};



#endif //CPP_RUSH2_2019_TABLE_HPP
