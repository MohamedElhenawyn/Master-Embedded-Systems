#include "mA.h"
int pressureVal_A;
int pressureThreshold = 20;
bool AlarmState;

void (*mA_Handler_state)();

void sendPressureVal(int ps_pressure_val)
{
    pressureVal_A = ps_pressure_val;
    STATE(pressureHandling)();
    //mA_Handler_state = STATE(pressureHandling);
}

STATE_define(pressureHandling)
{
    mA_state_id = pressureHandling;
    //Dprintf(3,"\n");
    if(pressureVal_A <= pressureThreshold)
    {
        sendAlarmState(false);
        mA_Handler_state = STATE(pressureHandling);
    }else{

        mA_Handler_state = STATE(AlarmHandling);
    }
}
STATE_define(AlarmHandling)
{
    mA_state_id = AlarmHandling;
    //Dprintf(3,"\n");
    sendAlarmState(true);
    mA_Handler_state = STATE(pressureHandling);
}

