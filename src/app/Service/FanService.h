#ifndef FANSERVICE_H
#define FANSERVICE_H

#include <string>
#include "FanView.h"

class FanService
{
private:
    int fanState;
    FanView *fanview;


public:
    FanService(FanView *fanview);
    ~FanService();
    void updateState(std::string strState);
};

#endif