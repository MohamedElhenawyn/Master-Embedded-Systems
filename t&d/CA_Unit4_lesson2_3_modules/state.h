#ifndef STATE_H_   
#define STATE_H_
#include <stdio.h>
#include <stdlib.h>
//Automatic state function generated
#define STATE_define(_stateFun_) void ST_##_stateFun_()
#define STATE(_stateFun_)  ST_##_stateFun_


//states connection
void Us_Set_distance(int dist);
void Dc_motor(int );
#endif