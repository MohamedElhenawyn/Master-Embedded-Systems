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
    //Dprintf(3,"\n");
    Set_Alarm_actuator(1);
    AH_state = STATE(idle);
}

STATE_define(AlarmActivate)
{
    AH_state_id = AlarmActivate;
    //Dprintf(3,"\n");
    Set_Alarm_actuator(0);
    Delay(30090000);
    Set_Alarm_actuator(1);
    AH_state = STATE(idle);

}