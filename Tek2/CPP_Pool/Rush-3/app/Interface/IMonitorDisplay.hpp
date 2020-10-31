//
// Created by Tornike on 2/1/20.
//

#ifndef RUSH_3_IMONITORDISPLAY_HPP
#define RUSH_3_IMONITORDISPLAY_HPP

#include <string>

class IMonitorDisplay {
    protected:
    int Xsize;
    int Ysize;
    std::string Name;

    public:
    explicit IMonitorDisplay(int xsize, int ysize, const std::string &name);
    virtual ~IMonitorDisplay();

    int getXsize() const;

    void setXsize(int xsize);

    int getYsize() const;

    void setYsize(int ysize);

    const std::string &getName() const;

    void setName(const std::string &name);

    virtual void initWindow() = 0;
    virtual void displayWindow() = 0;
};



#endif //RUSH_3_IMONITORDISPLAY_HPP
