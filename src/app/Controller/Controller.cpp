#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ, DHT11Service *dhtService, FanService *fanService)
{
    this->service = serv;
    this->clockService = clockServ;
    this->dhtService = dhtService;
    this->fanService = fanService;
    lightState = LIGHT_OFF;
}

Controller::~Controller()
{
}


void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }

    if (strBtn == "fanButton_on")
    {
        fanService->updateState("fanButton_on");
        service->updateEvent("fanButton_on");
    }
    else if (strBtn == "fanButton_off")
    {
        fanService->updateState("fanButton_off");
        service->updateEvent("fanButton_off");
    }

    if (strBtn == "stopwatchButton")
    {
        clockService->updateState("stopwatchButton");
    }

    if (strBtn == "stowatchstartstopButton")
    {
        clockService->updateState("stowatchstartstopButton");
    }

    if(strBtn == "clockUpdate")
    {
        clockService->updateEvent();
    }
}

void Controller::updateTempHumid(DHT_Data dhtData)
{
    dhtService->updateTempHumid(dhtData);
    service->updateTempHumid(dhtData);
}

void Controller::updateDistance(int distance)
{
    service->updateDistance(distance);
}