#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <string>
#include "Service.h"
#include "ClockService.h"
#include "DHT_Data.h"
#include "DHT11Service.h"
#include "FanService.h"

class Controller
{
private:
    int lightState;
    Service *service;
    ClockService *clockService;
    DHT11Service *dhtService;
    FanService *fanService;



public:
    Controller(Service *serv, ClockService *clockServ, DHT11Service *dhtService, FanService *fanService);
    virtual ~Controller();
    void updateEvent(std::string strBtn);
    void updateTempHumid(DHT_Data dhtData);
    void updateDistance(int distance);
};

#endif /* __CONTROLLER_H__ */