//
// Created by aguichet on 1/25/20.
//

#include "Elf.hpp"
#include "ConveyorBelt.hpp"

Elf::Elf()
: _Hand(nullptr)
{
}

Elf::~Elf()
{
}

bool Elf::TakeTable(Table *Table)
{
    int i = 0;

    if (Table->GetIsCollapse() || Table->_Object == nullptr || _Hand != nullptr)
        return (false);
    for (; Table->_Object[i] != nullptr; i++);
    i--;
    _Hand = Table->_Object[i];
    Table->_Object[i] = nullptr;
    return (true);
}

bool Elf::PutTable(Table *Table)
{
    int i = 0;

    if (Table->GetIsCollapse() || Table->_Object == nullptr || _Hand == nullptr)
        return (false);
    for (; Table->_Object[i] != nullptr; i++);
    if (i >= 10)
        return (false);
    Table->_Object[i] = _Hand;
    Table->_Object[i] = nullptr;
    return (true);
}

bool Elf::TakeConveyorBelt(ConveyorBelt *Conveyor)
{
    if (!Conveyor->GetisCharge() || _Hand != nullptr)
        return (false);
    _Hand = Conveyor->_Object;
    Conveyor->_Object = nullptr;
    Conveyor->_isCharge = false;
    return (true);
}

bool Elf::PutConveyorBelt(ConveyorBelt *Conveyor)
{
    if (!Conveyor->GetisCharge() || _Hand == nullptr)
        return (false);
    Conveyor->_Object = _Hand;
    Conveyor->_isCharge = true;
    _Hand = nullptr;
    return (true);
}

std::vector<std::string> &Elf::Look(Table *Table)
{
    std::vector<std::string> titles(11);
    int i = 0;

    if (Table->_Object == nullptr) {
        titles[0] = nullptr;
        return (titles);
    }
    for (; Table->_Object[i] != nullptr; i++) {
        titles[i] = Table->_Object[i]->getTitle();
    }
    titles[i] = nullptr;
    return (titles);
}