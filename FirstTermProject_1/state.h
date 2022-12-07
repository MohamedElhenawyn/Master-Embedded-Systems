#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define debug 
#ifdef debug
#define Dprintf(debug_level,...) if(debug_level > 1)\
                                   printf("Func name : %s,File name : %s line : %s\n",__func__,__FILE__,__LINE__);\
                                   printf(">>\t");\
                                   printf(__VA_ARGS__)
#endif

#define STATE_define(_state_) void ST_##_state_()
#define STATE(_state_) ST_##_state_

void sendPressureVal(int);



#endif