#ifndef PS_H_
#define PS_H_
#include "state.h"
#include "driver.h"
enum{
    ps_reading
}ps_state_id;

extern void (*ps_handler_state)();

void psHandler_init(void);
STATE_define(ps_reading);


#endif