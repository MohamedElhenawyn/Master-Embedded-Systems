#ifndef ALARMHANDLER_H_
#define ALARMHANDLER_H_
#include "state.h"
#include "sEos.h"
#include "driver/driver.h"
//#include "driver.h"
enum{
    idle,
    AlarmActivate
}AH_state_id;

extern void (*AH_state)();

void AH_init(void);
STATE_define(idle);
STATE_define(AlarmActivate);

#endif