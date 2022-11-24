#ifndef _STATE_H_
#define _STATE_H_

#include <stdio.h>
#include <stdlib.h>

#define STATE_define(_statefunc_) void ST_##_statefunc_()
#define STATE(_statefunc_) ST_##_statefunc_

//states connection
void Us_distance_set(int d);
void DC_motor(int s);

#endif