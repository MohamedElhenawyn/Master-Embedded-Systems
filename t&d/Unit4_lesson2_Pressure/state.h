#ifndef _STATE_H_
#define _STATE_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define STATE_define(_state_) void ST_##_state_()
#define STATE(_state_) ST_##_state_

//here we write the prototypes of the commun. bt. modules functions
void send_pressure(int);
void send_OnAlarm(bool);
void send_OffAlarm(bool);
#endif