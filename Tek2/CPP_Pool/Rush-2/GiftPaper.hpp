/*
** EPITECH PROJECT, 2019
** GiftPaper.hpp
** File description:
** GiftPaper Header
*/

#ifndef _GIFTPAPER_HPP_
#define _GIFTPAPER_HPP_

#include "Wrap.hpp"
#include "Object.hpp"

class GiftPaper : public Wrap, public Object
{
    public:
        GiftPaper(const std::string &Title);
        ~GiftPaper();
        void isWraped();
};

#endif
