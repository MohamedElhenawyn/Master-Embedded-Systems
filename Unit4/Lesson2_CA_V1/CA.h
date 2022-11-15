#ifndef CA_H_
#define CA_H_
#include "state.h"
//define states as enums 
enum{
    CA_Waiting,
    CA_Driving
}CA_state_id;

//declare states 
STATE_define(CA_Waiting);
STATE_define(CA_Driving);

extern void (* CA_state)();



#endif