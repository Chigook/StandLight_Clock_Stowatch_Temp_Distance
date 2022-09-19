#include "Listener.h"

Listener::Listener(Button *stowatchstartstopButton, Button *stopwatchButton, Button *modeButton, Button *fanButton, Controller *control, ClockCheck *clock, DHT11 *dht11, UltraSonic *ultraSonic)
{
    this->stowatchstartstopButton = stowatchstartstopButton;
    this->stopwatchButton = stopwatchButton;
    this->modeButton = modeButton;
    this->fanButton = fanButton;
    controller = control;
    clockCheck = clock;
    this->dht11 = dht11;
    this->ultraSonic = ultraSonic;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if (modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }

    if (fanButton->getState() == RELEASE_ACTIVE)
    {
        static int fanState = 0;
        fanState = !fanState;
        if(fanState == 1)
        {
            controller->updateEvent("fanButton_on");
        }
        else{
            controller->updateEvent("fanButton_off");
        }
    }

     if (stopwatchButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("stopwatchButton");
    }

    if (stowatchstartstopButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("stowatchstartstopButton");
    }

    if(clockCheck->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }

    static unsigned int prevTempHumidTime = 0;
    if(millis() - prevTempHumidTime > 2000)
    {
        prevTempHumidTime = millis();
        DHT_Data dhtData = dht11->readData();
        if(!dhtData.error){
            controller->updateTempHumid(dhtData);
        }
    }

    static unsigned int prevUltraSonicTime = 0;
    if(millis() - prevUltraSonicTime > 1000)
    {
        prevUltraSonicTime = millis();
        int distance = ultraSonic->readDistance();
        controller->updateDistance(distance);
    }

}