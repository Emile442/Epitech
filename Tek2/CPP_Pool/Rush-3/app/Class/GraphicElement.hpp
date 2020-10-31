//
// Created by Tornike on 2/1/20.
//

#ifndef RUSH_3_GRAPHICELEMENT_HPP
#define RUSH_3_GRAPHICELEMENT_HPP

#include <SFML/Graphics.hpp>
#include <string>

class GraphicElement {
    sf::Texture Texture;
    sf::Sprite Sprite;
    std::string FileName;

    public:
    explicit GraphicElement(const std::string &fileName);
    virtual ~GraphicElement();

    const sf::Texture &getTexture() const;

    void setTexture(const std::string &filename);

    sf::Sprite getSprite() const;

    void setSprite();

    const std::string &getFileName() const;

    void createFile();

    void setFileName(const std::string &fileName);
};



#endif //RUSH_3_GRAPHICELEMENT_HPP
