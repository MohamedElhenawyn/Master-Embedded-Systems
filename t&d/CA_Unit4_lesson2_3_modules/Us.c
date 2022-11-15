#include "Us.h"
//variables
int Us_distance = 0;


//state pointer to function
int Us_Get_distance_random(int l ,int r ,int count);
void (* Us_state)();

void Us_init()
{
    //init ultra sonic driver
    printf("Us_init\n");

}

STATE_define(Us_busy)
{
    //state name 
    Us_state_id = Us_busy;
    //state action
    //DC_Motor(speed)
    
    //event_check->>>>> Uslling the driver to check the distance
    //ultra_sonic_get_distance_fn(Us_distance)
    Us_distance = Us_Get_distance_random(45,55,1);
    //(Us_distance <= Us_thershold) ? (Us_state = STATE(Us_Waiting)): (Us_state = STATE(Us_Driving));
    printf("Us_busy state : distance = %d \n",Us_distance);
    fflush(stdout);
    Us_Set_distance(Us_distance);
    Us_state = STATE(Us_busy);
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