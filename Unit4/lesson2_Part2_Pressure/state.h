#ifndef _STATE_H_
#define _STATE_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define debug
#define DPRINTF(debug_level,...) if(debug_level > 1)\
                                    printf("@Func: %s ,File: %s ,Line: %d",__func__,__FILE__,__LINE__);\
                                    printf(">>\t");\
                                    printf(__VA_ARGS__)


#define STATE_define(_state_) void ST_##_state_()
#define STATE(_state_) ST_##_state_

//here we write the prototypes of the commun. bt. modules functions
void send_pressure(int);
void send_OnAlarm(bool);
void send_OffAlarm(bool);
#endif