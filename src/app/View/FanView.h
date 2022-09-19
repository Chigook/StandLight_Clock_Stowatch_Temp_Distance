#ifndef FANVIEW_H
#define FANVIEW_H

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>

enum {Fan_Off, Fan_On};

class FanView
{
private:
    int fanState;
    int pwmPin;

public:
    FanView(int pwm);
    ~FanView();
    void setState(int state);
    void fanstateView();
    void fanOff();
    void fanOn();


};

#endif