//
// Created by aguichet on 1/25/20.
//

#include "Table.hpp"

Table::Table()
: _NbObjects(0), _Object(nullptr), _IsCollapse(false)
{
}

Table::~Table()
{
}

int Table::GetNbObjects()
{
    if (_NbObjects > 10 && !GetIsCollapse())
        _IsCollapse = true;
    return _NbObjects;
}

bool Table::GetIsCollapse() const
{
    return _IsCollapse;
}
