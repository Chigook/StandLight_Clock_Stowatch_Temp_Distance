#ifndef __VIEW_H__
#define __VIEW_H__

#include <string>
#include <wiringPi.h>
#include <softPwm.h>
#include "Led.h"
#include "LightState.h"
#include "LCD.h"
#include "DHT_Data.h"


class View
{
private:
    int lightState;
    int temper;
    int pwmPin;
    int fanState;
    Led *light1;
    Led *light2;
    Led *light3;
    Led *light4;
    Led *light5;
    LCD *lcd;

public:
    View(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5, LCD *lcd, int pwm);
    virtual ~View();
    void setState(int state);
    void lightView();
    void lightOff();
    void lightOn_1();
    void lightOn_2();
    void lightOn_3();
    void lightOn_4();
    void lightOn_5();
    void setTempHumidData(float temp, float humid);
    void checkTemp();
    void checkTempState(std::string strState);
};

#endif /* __VIEW_H__ */