#include "FanView.h"

FanView::FanView(int pwm)
    : pwmPin(pwm)
{
    wiringPiSetup();
    softPwmCreate(pwmPin, 0, 100);
    fanState = Fan_Off;
}

FanView::~FanView()
{

}

void FanView::setState(int state)
{
    fanState = state;
}

void FanView::fanstateView()
{
    switch (fanState)
    {
    case Fan_Off:
        fanOff();
    break;
    case Fan_On:
        fanOn();
    break;
    }
}

void FanView::fanOff()
{
    softPwmWrite(pwmPin, 0);
}

void FanView::fanOn()
{
    softPwmWrite(pwmPin, 50);
}