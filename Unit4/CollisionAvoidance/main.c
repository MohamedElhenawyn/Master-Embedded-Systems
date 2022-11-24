#include "collision_avoidance.h"
#include "us_sensor.h"
#include "dc_motor.h"

void setup()
{
    //init all the drivers 
    //init the irqs
    //init the hal as us_driver Dc_driver
    //init blockCA
    //set states pointers for each
    us_init();
    DC_motor_init();
    CA_state = STATE(CA_waiting);
    Us_state = STATE(Us_busy);
    DC_motor_state = STATE(DC_idle);

}

int main(void)
{
    setup();
    while(1)
    {
        //call the state for each block
        Us_state();
        CA_state();
        DC_motor_state();      
        
    }
}