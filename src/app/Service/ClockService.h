#ifndef CLOCKSERVICE_H
#define CLOCKSERVICE_H

#include <time.h>
#include "ClockView.h"
#include "lcd.h"

enum {Clock, StopWatchWait, StopWatchStart};

class ClockService
{
private:
    int TimerState;
    time_t prevTime;
    time_t curTime;
    ClockView *clockView;
    LCD *lcd;

public:
    ClockService(ClockView *view, LCD *lcd);
    virtual ~ClockService();
    void updateEvent();
    void updateState(std::string strState);
};

#endif