#include "CA.h"
void setup()
{
    //init all the drivers 
    //init the irqs
    //init the hal as us_driver Dc_driver
    //init blockCA
    //set states pointers for each
    CA_state = STATE(CA_Waiting);

}

int main(void)
{
    setup();
    while(1)
    {
        //call the state for each block
        CA_state();
    }
}