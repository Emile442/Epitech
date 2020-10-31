/*
** EPITECH PROJECT, 2022
** Tek2
** File description:
** Created by Zebens,
*/

#include "GiftPaper.hpp"

GiftPaper::GiftPaper(const std::string &Title)
: Object(Title), Wrap()
{
}

GiftPaper::~GiftPaper()
{
}

void GiftPaper::isWraped()
{
    _isOpen = false;
}