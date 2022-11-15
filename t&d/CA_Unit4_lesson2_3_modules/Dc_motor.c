#include "Dc_motor.h"
//variables
int Dc_motor_speed = 0;
//state pointer to function
void (* Dc_motor_state)();


void DC_init()
{
    //init PWM
    printf("DC init\n");
}

void DC_motor(int s)
{
    Dc_motor_speed = s;
    Dc_motor_state = STATE(DC_busy);
    printf("CA-----speed = %d----->DC\n",Dc_motor_speed);
}

STATE_define(DC_idle)
{
    //state name 
    Dc_motor_state = DC_idle;
    //state action
    //DC_Motor(speed)
    //call pwm to make speed equals = dc_speed 

    //event_check->>>>> Dc_motorlling the driver to check the distance
    //ultra_sonic_get_distance_fn(Dc_motor_distance)
    //Dc_motor_distance = Us_Get_distance_random(45,55,1);
    printf("idle state = %d\n",Dc_motor_speed);
    fflush(stdout);
}
STATE_define(DC_busy)
{
    //state name
    Dc_motor_state = DC_busy; 
    //state action
    //DC_Motor(speed)
    //call pwm to make speed equals = dc_speed to change the speed

    //event_check.
    //ultra_sonic_get_distance_fn(Dc_motor_distance)
    //Dc_motor_distance = Us_Get_distance_random(45,55,1);
    //Dc_motor_distance <= Dc_motor_thershold) ? (Dc_motor_state = STATE(Dc_motor_Waiting)): (Dc_motor_state = STATE(Dc_motor_Driving));
    printf("busy state = %d\n",Dc_motor_speed);
    fflush(stdout);
    Dc_motor_state = DC_idle;
    //fflush(stdout);
}
