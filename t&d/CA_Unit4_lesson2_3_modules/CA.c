#include "CA.h"
//variables
int CA_speed = 0;
int CA_distance = 0;
int CA_thershold = 50;

//state pointer to function
//int Us_Get_distance_random(int l ,int r ,int count);
void (* CA_state)();


void Us_Set_distance(int dist)
{
    CA_distance = dist;
    (CA_distance <= CA_thershold) ? (CA_state = STATE(CA_Waiting)): (CA_state = STATE(CA_Driving));
    printf("US-----Distance = %d----->CA\n",CA_distance);
}
STATE_define(CA_Waiting)
{
    //state name 
    CA_state_id = CA_Waiting;
    printf("CA_waiting state : distance = %d speed = %d \n",CA_distance,CA_speed);
    //state action
    //DC_Motor(speed)
    CA_speed = 0;
    Dc_motor(CA_speed);
    //event_check->>>>> calling the driver to check the distance
    //ultra_sonic_get_distance_fn(CA_distance)
    //CA_distance = Us_Get_distance_random(45,55,1);
    
    
    fflush(stdout);
}
STATE_define(CA_Driving)
{
   //state name 
    CA_state_id = CA_Driving;
    printf("CA_driving state : distance = %d speed = %d \n",CA_distance,CA_speed);
    //state action
    //DC_Motor(speed)
    CA_speed = 30;
    Dc_motor(CA_speed);
    //event_check.
    //ultra_sonic_get_distance_fn(CA_distance)
    //CA_distance = Us_Get_distance_random(45,55,1);
    //CA_distance <= CA_thershold) ? (CA_state = STATE(CA_Waiting)): (CA_state = STATE(CA_Driving));
    
    //fflush(stdout);
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