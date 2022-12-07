#ifndef MA_H_
#define MA_H_
#include "state.h"

enum 
{
    pressureHandling,
    AlarmHandling
}mA_state_id;

STATE_define(pressureHandling);
STATE_define(AlarmHandling);

extern void (*mA_Handler_state)();


#endif