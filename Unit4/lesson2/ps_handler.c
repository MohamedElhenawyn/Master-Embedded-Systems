#include "ps_Handler.h"
//module variables
int pressureVal = 0;
//communication btn modules prototype
void send_pressure_val(unsigned int);
int generate_random(int min,int max ,int iterations);
void (*ps_handler_state)();
//apis definition

void ps_handler_init()
{
    printf("Ps_handler init \n");
    fflush(stdout);
}
STATE_define(ps_busy)
{
    ps_state_id = ps_busy;
    pressureVal = generate_random(15,25,1);
    printf("Pressure sensor busy state ,Pressure = %d\n",pressureVal);
    fflush(stdout);
    send_pressure(pressureVal);
    ps_handler_state = STATE(ps_busy);
}
int generate_random(int min,int max ,int iterations)
{
int i;
    for(i = 0;i < iterations; i++)
    {
        int rand_nunm = (rand() % (max - min + 1 )) + min ;
        return rand_nunm;
    }
}