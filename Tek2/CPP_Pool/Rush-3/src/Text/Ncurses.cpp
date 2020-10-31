//
// Created by aguichet on 2/1/20.
//

#include "../../app/Class/TextMonitorDisplay.hpp"
#include "../Modules/OSInfo/OSInfoModule.hpp"
#include "../Modules/CpuInfo/CpuInfoModule.hpp"
#include "../Modules/HostInfo/HostInfoModule.hpp"
#include "../Modules/DateTime/DateTimeModule.hpp"
#include "../Modules/RamInfo/RamInfoModule.hpp"
#include "../Modules/NetworkInfo/NetworkInfoModule.hpp"

TextMonitorDisplay::TextMonitorDisplay(int xsize, int ysize, const std::string &name)
: IMonitorDisplay(xsize, ysize, name)
{
}

TextMonitorDisplay::~TextMonitorDisplay()
= default;

WINDOW *TextMonitorDisplay::get_window() const
{
    return _window;
}

void TextMonitorDisplay::set_window(WINDOW *_window)
{
    TextMonitorDisplay::_window = _window;
}

void TextMonitorDisplay::display_color(std::string str, int pair)
{
    attron(COLOR_PAIR(pair));
    printw("%s", str.c_str());
    attroff(COLOR_PAIR(pair));
}

void TextMonitorDisplay::displayOS()
{
    OSInfoModule osInfo;

    display_color("------------------------------------", 4);
    printw("OS  INFO");
    display_color("------------------------------------", 4);
    printw("\nName : %s\nVersion : %s\nOS Version : %s\n", osInfo.getName().c_str(), osInfo.getVersion().c_str(), osInfo.getOsVersion().c_str());
    display_color("--------------------------------------------------------------------------------\n\n", 4);
}

void TextMonitorDisplay::displayHost()
{
    HostInfoModule hostInfo;

    display_color("-----------------------------------", 4);
    printw("HOST  INFO");
    display_color("-----------------------------------", 4);
    printw("\nHostname : %s\nUsername : %s\n", hostInfo.getName().c_str(), hostInfo.getUsername().c_str());
    display_color("--------------------------------------------------------------------------------\n\n", 4);
}

void TextMonitorDisplay::displayDate()
{
    DateTimeModule dateTime;

    display_color("-----------------------------------", 4);
    printw("DATE  TIME");
    display_color("-----------------------------------", 4);
    printw("\nDate : %s\nTime : %s\n", dateTime.getDate().c_str(), dateTime.getTime().c_str());
    display_color("--------------------------------------------------------------------------------\n\n", 4);
}

void TextMonitorDisplay::displayNetwork()
{
    NetworkInfoModule networkInfo;

    display_color("----------------------------------", 4);
    printw("NETWORK INFO");
    display_color("----------------------------------", 4);
    printw("\nUP : %s\nDOWN : %s\n", networkInfo.getUp().c_str(), networkInfo.getDown().c_str());
    display_color("--------------------------------------------------------------------------------\n\n", 4);
}

void TextMonitorDisplay::displayRAM()
{
    RamInfoModule ramInfo;
    float use = 100 * (strtof(ramInfo.getTotal().c_str(), nullptr) - strtof(ramInfo.getAvailable().c_str(), nullptr)) / strtof(ramInfo.getTotal().c_str(), nullptr);
    int nb_stick = use / 5;
    float mod = 5;

    if (fmod(use, mod) != 0)
        nb_stick++;
    display_color("------------------------------------", 4);
    printw("RAM INFO");
    display_color("------------------------------------", 4);
    printw("\n\t[");
    for (int i = 0; i < nb_stick; i++) {
        if (i < 7)
            display_color("|", 1);
        if (i >= 7 && i < 13)
            display_color("|", 2);
        if (i >= 13)
            display_color("|", 3);
    }
    for (int i = 0; i < 20 - nb_stick; i++) {
        printw(" ");
    }
    printw("]\tTotal : %s Ko\tAvailable : %s Ko\n", ramInfo.getTotal().c_str(), ramInfo.getAvailable().c_str());
    display_color("--------------------------------------------------------------------------------\n\n", 4);
}

void TextMonitorDisplay::displayCPU()
{
    CpuInfoModule CPUInfo;
    int nb_stick = 0;
    float mod = 5;

    std::vector<CPUUsage> tmp = CPUInfo.getUsage();
    size_t sizeTmp = tmp.size();
    display_color("------------------------------------", 4);
    printw("CPU INFO");
    display_color("------------------------------------\n", 4);
    for (size_t i = 0; i < sizeTmp; i++) {
        printw("%s\t[", tmp[i].nbr.c_str());
        nb_stick = tmp[i].active / 5;
        if (fmod(tmp[i].active, mod) != 0)
            nb_stick++;
        for (int i = 0; i < nb_stick; i++) {
            if (i < 7)
                display_color("|", 1);
            if (i >= 7 && i < 13)
                display_color("|", 2);
            if (i >= 13)
                display_color("|", 3);
        }
        for (int i = 0; i < 20 - nb_stick; i++) {
            printw(" ");
        }
        printw("]\tACTIVE : %f %%\tIDLE : %f %%\n", tmp[i].active, tmp[i].idle);
    }
    display_color("--------------------------------------------------------------------------------\n", 4);
}

bool TextMonitorDisplay::check_size()
{
    if (LINES < 31 || COLS < 80)
        return (false);
    return (true);
}

void TextMonitorDisplay::initcolor()
{
    init_color(COLOR_MAGENTA, 1000, 650, 0);
    start_color();
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
}

void TextMonitorDisplay::check_touch(int ch)
{
    if (ch == '1')
        _displayOS = !_displayOS;
    if (ch == '2')
        _displayHOST = !_displayHOST;
    if (ch == '3')
        _displayDATE = !_displayDATE;
    if (ch == '4')
        _displayRAM = !_displayRAM;
    if (ch == '5')
        _displayNETWORK = !_displayNETWORK;
    if (ch == '6')
        _displayCPU = !_displayCPU;
}

void TextMonitorDisplay::displayWindow()
{
    if (check_size() == true) {
        if (_displayOS == true)
            displayOS();
        if (_displayHOST == true)
            displayHost();
        if (_displayDATE == true)
            displayDate();
        if (_displayRAM == true)
            displayRAM();
        if (_displayNETWORK == true)
            displayNetwork();
        if (_displayCPU == true)
            displayCPU();
    } else {
        mvprintw((LINES - 1) / 2, (COLS - 43) / 2, "Terminal too small! Please enlarge him\n");
    }
}

void TextMonitorDisplay::loopwindow()
{
    int ch = getch();

    while (ch != 27 && ch != 'q') { //27 = echap
        clear();
        initcolor();
        check_touch(ch);
        check_size();
        displayWindow();
        refresh();
        usleep(500000);
        ch = getch();
    }
}

void TextMonitorDisplay::inittouch()
{
    _displayOS = true;
    _displayHOST = true;
    _displayDATE = true;
    _displayRAM = true;
    _displayNETWORK = true;
    _displayCPU = true;
}

void TextMonitorDisplay::initWindow()
{
    set_window(initscr()); //Initialise la window
    if (curs_set(1) == ERR) //Afficher le curseur (0 = invisible, 1 = normal, 2 = tres visible)
        set_window(nullptr);
    if (nodelay(_window, true) == ERR) //Pour getch (true = ne fais pas de pause, false = attend qu'une touche soit appuyé)
        set_window(nullptr);
    if (cbreak() == ERR) //Pas piger ce que c'est mais askip c'est cool;
        set_window(nullptr);
    if (noecho() == ERR) //N'affiche pas les character quand ils sont getch
        set_window(nullptr);
    if (keypad(stdscr, true) == ERR) //Permet de traiter les charactere speciaux
        set_window(nullptr);
}

int ncurses()
{
    TextMonitorDisplay window;
    window.initWindow();
    if (window.get_window() == nullptr)
        return (-1);
    window.inittouch();
    window.loopwindow();
    if (endwin() == ERR)
        return (-1);
    return (0);
}