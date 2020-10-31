//
// Created by Tornike on 2/1/20.
//

#include "GraphicMonitorDisplay.hpp"

GraphicMonitorDisplay::GraphicMonitorDisplay(int xsize, int ysize, const std::string &name)
: IMonitorDisplay(xsize, ysize, name), Background(DEFAULT_BACKGROUND_FILE), Window(sf::VideoMode(xsize, ysize), name)
{
}

void GraphicMonitorDisplay::initWindow()
{
    Window.setFramerateLimit(24);
    Background.createFile();
}

void GraphicMonitorDisplay::displayWindow()
{
    sf::Event event{};

    setInfoText();
    setRectModules();
    setProgressBar();
    while (Window.isOpen()) {
        while (Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                Window.close();
                exit(0);
            }
        }
        Window.clear();
        Window.draw(Background.getSprite());
        displayModules();
        Window.display();
    }
}

std::vector<sf::RectangleShape> GraphicMonitorDisplay::getRectModules() const
{
    return rectModules;
}

void GraphicMonitorDisplay::setRectModules()
{
    sf::RectangleShape tmp;
    sf::Vector2f pos = {0, 0};
    sf::Vector2f size = {static_cast<float>((Window.getSize().x / 4)), static_cast<float>(Window.getSize().y / 2)};

    for (int i = 0; i < NB_MODULES - 1; i++) {
        tmp.setSize(size);
        tmp.setPosition(pos);
        rectModules.push_back(tmp);
        pos.x += tmp.getSize().x;
        if (i == 3) {
            pos.x = 0;
            pos.y += tmp.getSize().y;
        }
    }
}

void GraphicMonitorDisplay::setInfoText()
{
    font.loadFromFile(DEFAULT_BACKGROUND_FONT);
    textInfo.setFont(font);
    textInfo.setCharacterSize(17);
    textInfo.setColor(sf::Color::White);
    textInfo.setStyle(sf::Text::Bold);
    textInfo.setOrigin(0, 0);
}

void GraphicMonitorDisplay::setProgressBar()
{
    sf::RectangleShape tmp;
    sf::Vector2f size = {9, 37};
    sf::Vector2f pos = rectModules[5].getPosition();

    pos.x += 30;
    for (int i = 0; i < 33; i++) {
        tmp.setSize(size);
        tmp.setPosition(pos);
        if (i < 11)
            tmp.setFillColor(sf::Color::Green);
        else if (i < 22 && i >= 11)
            tmp.setFillColor(sf::Color::Yellow);
        else
            tmp.setFillColor(sf::Color::Red);
        progressBar.push_back(tmp);
        pos.x += size.x + 2;
    }
}
