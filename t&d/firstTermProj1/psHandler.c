#include "psHandler.h"

int pressureVal = 0;

void (*ps_handler_state)();
int getRandom(int min ,int max,int count);
void psHandler_init(void)
{
    //Dprintf(3,"\n");
    GPIO_INITIALIZATION();
}

STATE_define(ps_reading)
{
    ps_state_id = ps_reading;
    //Dprintf(3,"\n");
    //pressureVal = getRandom(15,25,1);
    pressureVal = getPressureVal();
    //printf("PressureValue ---- = %d ---->MainAlgorithm\n",pressureVal);
    //fflush(stdout);
    sendPressureVal(pressureVal);
    ps_handler_state = STATE(ps_reading);
}

/*
int getRandom(int min,int max,int count)
{
    int i;
    Dprintf(3,"\n");
    for(i = 0;i < count; i++)
    {
        int rand_nunm = (rand() % (max - min + 1 )) + min ;
        return rand_nunm;
    }
}
*/