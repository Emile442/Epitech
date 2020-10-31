//
// Created by aguichet on 1/25/20.
//

#include "Wrap.hpp"

Wrap::Wrap()
{
    _content = nullptr;
    _isOpen = false;
}

Wrap::~Wrap()
{
}

bool Wrap::wrapMeThat(Object *object)
{
    if (object || !_content) {
        _content = object;
        _isOpen = false;
        std::cout << "tuuuut tuuut tuut" << std::endl;
        return true;
    }
    return false;
}

void Wrap::openMe()
{
    _isOpen = true;
}

bool Wrap::GetIsOpen() const
{
    return _isOpen;
}

Object *Wrap::accessObject()
{
    if (!_isOpen)
        return nullptr;
    return _content;
}