#ifndef _COLLISION_AVOIDANCE_H_
#define _COLLISION_AVOIDANCE_H_
#include "state.h"
enum{
    CA_waiting,
    CA_driving
}CA_State_id;

STATE_define(CA_waiting);

STATE_define(CA_driving);

extern void (*CA_state) ();

#endif