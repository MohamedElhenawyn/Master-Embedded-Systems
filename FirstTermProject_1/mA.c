#include "mA.h"
int pressureVal_A;
int pressureThreshold = 20;
bool AlarmState;

void sendPressureVal(int ps_pressure_val)
{
    pressureVal_A = ps_pressure_val;
    STATE(pressureHandling)();
}

STATE_define(pressureHandling)
{
    mA_state_id = pressureHandling;

}

