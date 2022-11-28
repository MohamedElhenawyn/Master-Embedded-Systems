#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_
#include "state.h"

enum{
    Controller_busy,
    Contoller_AlarmOn,
    Contoller_AlarmOff
}contoller_state_id;

STATE_define(Controller_busy);
STATE_define(Contoller_AlarmOn);
STATE_define(Contoller_AlarmOff);

extern void (* controller_state)();

#endif