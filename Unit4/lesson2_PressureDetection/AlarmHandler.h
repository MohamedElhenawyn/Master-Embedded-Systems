#ifndef _ALARM_HANDLER_H_
#define _ALARM_HANDLER_H_
#include "state.h"

enum{
    AlarmHandler,
    AlarmOn,
    AlarmOff
}AH_state_id;

void AH_init();
STATE_define(AlarmHandler);
STATE_define(AlarmOn);
STATE_define(AlarmOff);

extern void (*AH_state)();

#endif