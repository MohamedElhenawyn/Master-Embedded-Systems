#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


#define Dprintf(debug_level,...) if(debug_level > 1) \
									printf("@Func: %s,File: %s, Line: %d",__func__,__FILE__,__LINE__);\
									printf(">> \t");\
									printf(__VA_ARGS__)

#define STATE_define(_state_) void ST_##_state_()
#define STATE(_state_) ST_##_state_

void sendPressureVal(int);
void sendAlarmState(bool);


#endif