#ifndef ALARM_SYSTEM_CONTROLLER_H
#define ALARM_SYSTEM_CONTROLLER_H

#include "observer.h"

typedef struct {
    subscriber_t base;
} alarm_system_controller_t;

subscriber_t* create_alarm_system_controller(void);

#endif // ALARM_SYSTEM_CONTROLLER_H
