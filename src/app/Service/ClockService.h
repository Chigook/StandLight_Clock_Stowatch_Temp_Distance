#ifndef CLOCKSERVICE_H
#define CLOCKSERVICE_H

#include <time.h>
#include "ClockView.h"

class ClockService
{
private:
    int TimerState;
    time_t curTime;
    ClockView *clockView;

public:
    ClockService(ClockView *view);
    virtual ~ClockService();
    void updateEvent();
    void updateState(std::string strState);
};

#endif