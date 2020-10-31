//
// Created by Tornike on 2/1/20.
//

#include "GraphicElement.hpp"

GraphicElement::GraphicElement(const std::string &fileName) : FileName(fileName)
{
}

const sf::Texture &GraphicElement::getTexture() const
{
    return Texture;
}

void GraphicElement::setTexture(const std::string &filename)
{
    Texture.loadFromFile(filename);
}

sf::Sprite GraphicElement::getSprite() const
{
    return Sprite;
}

void GraphicElement::setSprite()
{
    Sprite.setTexture(getTexture());
}

const std::string &GraphicElement::getFileName() const
{
    return FileName;
}

void GraphicElement::setFileName(const std::string &fileName)
{
    FileName = fileName;
}

void GraphicElement::createFile()
{
    setTexture(getFileName());
    setSprite();
}

GraphicElement::~GraphicElement()
= default;

