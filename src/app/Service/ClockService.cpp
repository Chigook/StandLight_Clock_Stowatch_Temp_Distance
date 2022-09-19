#include "ClockService.h"
#include <iostream>

ClockService::ClockService(ClockView *view, LCD *lcd)
{
    prevTime = 0;
    curTime = 0;
    clockView = view;
    TimerState = Clock;
    this->lcd = lcd;
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
                TimerState = StopWatchWait;
                prevTime = time(NULL)+32401;
            }
            if (strState == "stowatchstartstopButton") {
                TimerState = Clock;
            }
        break;

        case StopWatchWait:
            if (strState == "stopwatchButton") {
                TimerState = Clock;
            }
            if (strState == "stowatchstartstopButton") {
                TimerState = StopWatchStart;
            }
        break;

        case StopWatchStart:
            if (strState == "stowatchstartstopButton"){
                TimerState = StopWatchWait;
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
        printf("Clock\n");
    }

    if(TimerState == StopWatchStart)
    {
        curTime = time(NULL) - prevTime;
        struct tm *timeDate = localtime(&curTime);
        clockView->updatetime(timeDate);
        printf("StopWatchStar\n");
    }

    if(TimerState == StopWatchWait){
        curTime = 0;
        struct tm *timeDate = localtime(&curTime);
        clockView->updatetime(timeDate);  
        printf("StopWatchWait\n");      
    }
}