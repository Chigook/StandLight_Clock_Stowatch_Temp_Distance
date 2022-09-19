#include "ClockService.h"
#include <iostream>

ClockService::ClockService(ClockView *view)
{
    curTime = 0;
    clockView = view;
    TimerState = 0;
}

ClockService::~ClockService()
{

}

void ClockService::updateState(std::string strState)
{
    switch(TimerState)
    {
        case 0:
            if (strState == "stopwatchButton") {
                TimerState = 1;
                // view->setState(TimerState);
            }
        break;

        case 1:
            if (strState == "stopwatchButton") {
                TimerState = 0;
                // view->setState(TimerState);
            }
            break;
    }
}

void ClockService::updateEvent()
{
    curTime = time(NULL);
    struct tm *timeDate = localtime(&curTime);
    clockView->updatetime(timeDate);
}