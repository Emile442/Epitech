//
// Created by aguichet on 1/25/20.
//

#include "ConveyorBelt.hpp"

ConveyorBelt::ConveyorBelt()
: _isCharge(true), _Object(NULL), _Wrap(NULL)
{
}

ConveyorBelt::~ConveyorBelt()
{
}

bool ConveyorBelt::GetisCharge() const
{
    return _isCharge;
}

void ConveyorBelt::INButton(Wrap *Wrap)
{
    if (Wrap == NULL) {
        std::cerr << "ERROR : Pushing IN button and received nothing." << std::endl;
        return;
    }
    _Wrap = Wrap;
    _isCharge = true;
}

Wrap *ConveyorBelt::OUTButton()
{
    if (_Object == NULL) {
        std::cerr << "ERROR : Pushing OUT button without anything on conveyor." << std::endl;
        return (NULL);
    }
    _isCharge = false;
    _Object = NULL;
    return (_Wrap);
}