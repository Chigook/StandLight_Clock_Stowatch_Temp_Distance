#ifndef __LISTENER_H__
#define __LISTENER_H__

#include "Button.h"
#include "Controller.h"
#include "ClockCheck.h"
#include "DHT11.h"
#include "DHT_Data.h"
#include <wiringPi.h>
#include "UltraSonic.h"

class Listener
{
private :
    Button *stowatchstartstopButton;
    Button *stopwatchButton;
    Button *modeButton;
    Button *fanButton;
    Controller *controller;
    ClockCheck *clockCheck;
    DHT11 *dht11;
    UltraSonic *ultraSonic;

public:
    Listener(Button *stowatchstartstopButton, Button *stopwatchButton, Button *modebutton, Button *fanButton, Controller *control, ClockCheck *clock, DHT11 *dht11, UltraSonic *ultraSonic);
    ~Listener();
    void checkEvent();
};

#endif /* __LISTENER_H__ */