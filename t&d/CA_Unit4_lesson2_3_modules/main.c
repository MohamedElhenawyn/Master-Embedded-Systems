#include "CA.h"
#include "Us.h"
#include "Dc_motor.h"

void setup()
{
    //init all the drivers 
    //init the irqs
    //init the hal as us_driver Dc_driver
    //init blockCA
    //set states pointers for each
    Us_init();
    DC_init();
    CA_state = STATE(CA_Waiting);
    Us_state = STATE(Us_busy);
    DC_state = STATE(DC_idle);

}

int main(void)
{
    setup();
    while(1)
    {
        //call the state for each block
        Us_state();
        CA_state();
        DC_state();      
        
    }
}