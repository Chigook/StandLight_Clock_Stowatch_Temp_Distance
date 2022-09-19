#include "FanService.h"

FanService::FanService(FanView *fanview)
{
    this->fanview = fanview;
    fanState = Fan_Off;
}

FanService::~FanService()
{

}

void FanService::updateState(std::string strState)
{
    switch(fanState)
    {
    static bool state = 0;
    case Fan_Off:
        if (strState == "fanButton_off")
        {
            state = 0;
            fanview->setState(state);
            fanState = !fanState;
        }
        break;

    case Fan_On:
        if (strState == "fanButton_on")
        {
            state = 1;
            fanview->setState(state);
            fanState = !fanState;
        }
        break;
    }
}