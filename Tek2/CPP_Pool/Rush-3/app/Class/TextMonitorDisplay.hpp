//
// Created by aguichet on 2/1/20.
//

#ifndef RUSH_3_TEXTMONITORDISPLAY_HPP
#define RUSH_3_TEXTMONITORDISPLAY_HPP

#include "../Interface/IMonitorDisplay.hpp"
#include <curses.h>
#include <unistd.h>
#include <math.h>

class TextMonitorDisplay : public IMonitorDisplay {
    public:
    explicit TextMonitorDisplay(int xsize = 100, int ysize = 20, const std::string &name = "MyGKrellm");
    ~TextMonitorDisplay() override;
    void initWindow() override;
    void displayWindow() override;
    void displayCPU();
    void displayOS();
    void displayHost();
    void displayDate();
    void displayRAM();
    void displayNetwork();
    void initcolor();
    void inittouch();
    bool check_size();
    void display_color(std::string str, int pair);
    void check_touch(int ch);
    void loopwindow();
    WINDOW *get_window() const;
    void set_window(WINDOW *_window);

    private:
    WINDOW *_window;
    bool _displayOS;
    bool _displayHOST;
    bool _displayDATE;
    bool _displayRAM;
    bool _displayNETWORK;
    bool _displayCPU;
};

int ncurses();

#endif //RUSH_3_TEXTMONITORDISPLAY_HPP
