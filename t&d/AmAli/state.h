#ifndef STATE_H_
#define STATE_H_
#include <stdbool.h>
#define STATE_define(_state_) void ST_##_state_()
#define STATE(_state_) ST_##_state_


void Buttons_send_Values(bool Man,bool Auto,bool startFrwd,bool startRev,bool stop,bool proximity_first,bool proximity_last);

#endif