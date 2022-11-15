#ifndef Us_H_
#define Us_H_
#include "state.h"
//define states as enums 
enum{
    Us_busy
}Us_state_id;

//declare states 

STATE_define(Us_busy);
void Us_init();
extern void (* Us_state)();



#endif