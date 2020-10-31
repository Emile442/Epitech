//
// Created by Tornike on 2/1/20.
//

#ifndef RUSH_3_GRAPHICMONITORDISPLAY_HPP
#define RUSH_3_GRAPHICMONITORDISPLAY_HPP

#include <string>
#include "../Interface/IMonitorDisplay.hpp"
#include "GraphicElement.hpp"

//----------------------MODULES----------------------//
#include "../../src/Modules/DateTime/DateTimeModule.hpp"
#include "../../src/Modules/Diskinfo/SubModules/DiskInfoModule.hpp"
#include "../../src/Modules/HostInfo/HostInfoModule.hpp"
#include "../../src/Modules/NetworkInfo/NetworkInfoModule.hpp"
#include "../../src/Modules/OSInfo/OSInfoModule.hpp"
#include "../../src/Modules/RamInfo/RamInfoModule.hpp"
#include "../../src/Modules/CpuInfo/CpuInfoModule.hpp"

//--------------------------------------------//

#define DEFAULT_BACKGROUND_FILE "resources/img/defaultbackground.png"
#define DEFAULT_BACKGROUND_FONT "resources/fonts/arial.ttf"

#define NB_MODULES (7)

class GraphicMonitorDisplay : public IMonitorDisplay {
    GraphicElement Background;
    sf::RenderWindow Window;
    std::vector<sf::RectangleShape> rectModules;
    std::vector<sf::RectangleShape> progressBar;
    sf::Text textInfo;
    sf::Font font;

    public:
    explicit GraphicMonitorDisplay(int xsize = 1280, int ysize = 720, const std::string &name = "");

    std::vector<sf::RectangleShape>getRectModules() const;
    void setRectModules();

    void displayModules();

    void setInfoText();

    void setProgressBar();

    virtual void initWindow() override;
    virtual void displayWindow() override;

};

#endif //RUSH_3_GRAPHICMONITORDISPLAY_HPP
