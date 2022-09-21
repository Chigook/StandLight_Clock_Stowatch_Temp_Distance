#include "ClockService.h"
#include <iostream>

ClockService::ClockService(ClockView *view)
{
    prevTime = 0;
    curTime = 0;
    clockView = view;
    TimerState = Clock;
}

ClockService::~ClockService()
{

}

void ClockService::updateState(std::string strState)
{
    switch(TimerState)
    {
        case Clock:
            if (strState == "stopwatchButton") {
                TimerState = StopWatchStart;
                prevTime = time(NULL)+32400;
            }
        break;

        case StopWatchStart:
            if (strState == "stopwatchButton")
            {
                TimerState = StopWatchWait;
                prevTime = curTime;
            }
        break;

        case StopWatchWait:
            if (strState == "stopwatchButton") {
                TimerState = Clock;
            }
        break;
    }
}

void ClockService::updateEvent()
{
    if(TimerState == Clock)
    {
        curTime = time(NULL);
        struct tm *timeDate = localtime(&curTime);
        clockView->updatetime(timeDate);
    }

    if(TimerState == StopWatchStart){
        curTime = time(NULL) - prevTime;
        struct tm *timeDate = localtime(&curTime);
        clockView->updatetime(timeDate);
    }

    if(TimerState == StopWatchWait)
    {
        struct tm *timeDate = localtime(&curTime);
        clockView->updatetime(timeDate);
    }

}