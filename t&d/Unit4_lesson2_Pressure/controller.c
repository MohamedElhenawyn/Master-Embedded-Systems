#include "controller.h"

int cPressureVal = 0;
int cPressureThreshold = 20;
void (* controller_state)();

void send_pressure(int sPressure)
{
    cPressureVal = sPressure;
    printf("PressureValue ------ pressureHandler = %d----->Controller\n",cPressureVal);
    fflush(stdout);

    STATE(Controller_busy)();

}
STATE_define(Controller_busy)
{

    printf("Controller busy State\n");
    fflush(stdout);
    (cPressureVal <= cPressureThreshold) ? (controller_state = STATE(Contoller_AlarmOff)):(controller_state = STATE(Contoller_AlarmOn));

}

STATE_define(Contoller_AlarmOff)
{
    contoller_state_id = Contoller_AlarmOff;
    printf("controller-----AlarmHadlerSignal = Off -->AlarmHandler\n");
    fflush(stdout);
    send_OffAlarm(true);
    controller_state = STATE(Controller_busy);
}
STATE_define(Contoller_AlarmOn)
{
    contoller_state_id = Contoller_AlarmOn;
    printf("controller-----AlarmHadlerSignal = ON -->AlarmHandler\n");
    fflush(stdout);
    send_OnAlarm(true);
    controller_state = STATE(Controller_busy);
}