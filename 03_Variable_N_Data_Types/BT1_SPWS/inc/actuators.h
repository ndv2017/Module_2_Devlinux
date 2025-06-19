#ifndef ACTUATORS_H
#define ACTUATORS_H

#include "config.h"

void actuators_init(void);
void turn_pump_on(void);
void turn_pump_off(void);
void update_led(led_status_t status);
void notify_status(const char* msg);

#endif // ACTUATORS_H
