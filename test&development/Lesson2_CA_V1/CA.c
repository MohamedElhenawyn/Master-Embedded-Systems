#include "CA.h"
//variables
int CA_speed = 0;
int CA_distance = 0;
int CA_thershold = 50;

//state pointer to function
int Us_Get_distance_random(int l ,int r ,int count);
void (* CA_state)();

STATE_define(CA_Waiting)
{
    //state name 
    CA_state_id = CA_Waiting;
    //state action
    //DC_Motor(speed)
    CA_speed = 0;
    //event_check->>>>> calling the driver to check the distance
    //ultra_sonic_get_distance_fn(CA_distance)
    CA_distance = Us_Get_distance_random(45,55,1);
    (CA_distance <= CA_thershold) ? (CA_state = STATE(CA_Waiting)): (CA_state = STATE(CA_Driving));
    printf("CA_waiting state : distance = %d speed = %d \n",CA_distance,CA_speed);
    fflush(stdout);
}
STATE_define(CA_Driving)
{
   //state name 
    CA_state_id = CA_Driving;
    //state action
    //DC_Motor(speed)
    CA_speed = 30;
    //event_check.
    //ultra_sonic_get_distance_fn(CA_distance)
    CA_distance = Us_Get_distance_random(45,55,1);
    (CA_distance <= CA_thershold) ? (CA_state = STATE(CA_Waiting)): (CA_state = STATE(CA_Driving));
    printf("CA_driving state : distance = %d speed = %d \n",CA_distance,CA_speed);
    fflush(stdout);
}

int Us_Get_distance_random(int l ,int r ,int count)// l is low number r is maximum number count is the number of iterations
{
    int i;
    for(i = 0;i < count; i++)
    {
        int rand_nunm = (rand() % (r - l + 1 )) + l ;
        return rand_nunm;
    }
}