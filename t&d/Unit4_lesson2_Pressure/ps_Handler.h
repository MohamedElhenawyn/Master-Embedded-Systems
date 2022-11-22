#ifndef PS_HANDLER_H_
#define PS_HANDLER_H_
#include "state.h"

enum{
    ps_busy
}ps_state_id;

extern void (*ps_handler_state)();

void ps_handler_init();
STATE_define(ps_busy);


#endif