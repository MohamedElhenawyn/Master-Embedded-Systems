#include "AlarmHandler.h"
#include "controller.h"
#include "ps_Handler.h"

void setup()
{
    ps_handler_init();
    AH_init();
    ps_handler_state = STATE(ps_busy);
    controller_state = STATE(Controller_busy);
    AH_state = STATE(AlarmHandler);
}
void __attribute__((constructor)) setup();
int main (void)
{
    //setup();
    while(1)
    {
        ps_handler_state();
        controller_state();
        AH_state();
    }

    return 0;
}