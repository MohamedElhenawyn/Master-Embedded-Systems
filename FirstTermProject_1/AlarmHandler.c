#include "AlarmHandler.h"

bool AlarmState;
void (*AH_state)();
void sendAlarmState(bool AlarmValue)
{
    AlarmState = AlarmValue;
    if(AlarmState == true)
    {
        AH_state = STATE(AlarmActivate);
    }else{
        AH_state = STATE(idle);
    }
}
STATE_define(idle)
{
    AH_state_id = idle;
    Set_Alarm_actuator(0);
    AH_state = STATE(idle);
}

STATE_define(AlarmActivate)
{
    AH_state_id = AlarmActivate;
    Set_Alarm_actuator(1);
    Delay(50000);
    Set_Alarm_actuator(0);
    AH_state = STATE(idle);

}