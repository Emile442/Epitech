//
// Created by aguichet on 1/25/20.
//

#ifndef CPP_RUSH2_2019_ELF_HPP
#define CPP_RUSH2_2019_ELF_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "Table.hpp"
#include "ConveyorBelt.hpp"

class Elf {
    public:
        Elf();
        ~Elf();
        std::vector<std::string> &Look(Table *Table);
        bool TakeTable(Table *Table);
        bool PutTable(Table *Table);
        bool TakeConveyorBelt(ConveyorBelt *Conveyor);
        bool PutConveyorBelt(ConveyorBelt *Conveyor);
    private:
        Object *_Hand;
};



#endif //CPP_RUSH2_2019_ELF_HPP
