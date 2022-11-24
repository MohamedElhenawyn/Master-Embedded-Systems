#include"us_sensor.h"

//module variables 
unsigned int distance;
void (*Us_state) ();
void us_init()
{
    //init us sensor
    printf("Us_sensor Init \n");
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
STATE_define(Us_busy)
{
    //state action
    Us_state_id = Us_busy; 

    //read from the us
    distance = generate_random(45,55,1);
    printf("Us_busy State: distance = %d \n",distance);
    //send the distance to the collision avoidance algorithm
    Us_distance_set(distance);

    Us_state = STATE(Us_busy);
}