#include "AlarmHandler.h"

//module variables
bool alarmOn ;
bool alarmOff;
void (*AH_state)();

void AH_init()
{
    printf("AlarmHandler init\n");
}
void send_OnAlarm(bool x)
{
    printf("Recieve on alarm from the controller\n");
    fflush(stdout);
    alarmOn = x;
}
void send_OffAlarm(bool x)
{
    printf("No alarm recieved from the controller\n");
    fflush(stdout);
    alarmOff = x;
}
STATE_define(AlarmHandler)
{
    AH_state_id = AlarmHandler;
    (alarmOn == true)?(AH_state = STATE(AlarmOn)):(AH_state = STATE(AlarmHandler));
    (alarmOff == true)?(AH_state = STATE(AlarmOff)):(AH_state = STATE(AlarmHandler));
}
STATE_define(AlarmOn)
{
    printf("ALARM ON STATE \n");
    //calculate time here for 60s and open the gpio handler
    AH_state = STATE(AlarmHandler);
}
STATE_define(AlarmOff)
{
    printf("Alarm off state\n");
    AH_state = STATE(AlarmHandler);
}