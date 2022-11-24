#ifndef _STATE_H
#define _STATE_H

#include "state.h"

enum{
    Us_busy
}Us_state_id;

//prototypes
void us_init();
STATE_define(Us_busy);

extern void (*Us_state) ();

#endif