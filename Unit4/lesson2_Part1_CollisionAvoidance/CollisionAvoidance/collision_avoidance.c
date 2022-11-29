#include "collision_avoidance.h"

//module variables 
unsigned int CA_speed =0;
unsigned int CA_distance =0;
unsigned int CA_threshold = 50;
void (*CA_state) ();
void Us_distance_set(int d)
{
    CA_distance = d;
    printf("Us_sensor ---distance = %d---> CA_algorithm \n",CA_distance);
    fflush(stdout);
    (CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)): (CA_state = STATE(CA_driving));
}

STATE_define(CA_waiting)
{
    //State name
    CA_State_id = CA_waiting;
    //state action
    CA_speed = 0;
    DC_motor(CA_speed);
    printf("CA_waiting_state: distance = %d speed = %d\n",CA_distance,CA_speed);
    fflush(stdout);
    
}
STATE_define(CA_driving)
{
    //State action
    CA_State_id = CA_driving;
    CA_speed = 30;
    printf("CA_waiting_state: distance = %d speed = %d\n",CA_distance,CA_speed);
    fflush(stdout);
    
    DC_motor(CA_speed);
}