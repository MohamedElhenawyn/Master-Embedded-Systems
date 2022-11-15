#ifndef DC_motor_H_
#define DC_motor_H_
#include "state.h"
//define states as enums 
enum{
    DC_idle,
    DC_busy
}DC_state_id;

//declare states 
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

extern void (* DC_state)();



#endif