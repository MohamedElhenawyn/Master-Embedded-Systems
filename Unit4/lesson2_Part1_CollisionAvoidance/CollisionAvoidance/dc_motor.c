#include"dc_motor.h"

//module variables 
int speed = 0;
void (*DC_motor_state)();
void DC_motor_init()
{
    //init dc_motor
    printf("DC_Module init\n");
}
void DC_motor(int s)
{
    speed = s;
    printf("CA ---speed = %d---->DC_motor \n",speed);
    DC_motor_state = STATE(DC_busy);
    fflush(stdout);
}
STATE_define(DC_idle)
{
    //state name 
    DC_State_id = DC_idle;
    printf("DC idle state \n");
}
STATE_define(DC_busy)
{
    //state name
    DC_State_id = DC_busy;
    printf("DC busy state speed = %d \n",speed);
    DC_motor_state = STATE(DC_idle);
}
