#ifndef WATERING_LOGIC_H
#define WATERING_LOGIC_H

#include "config.h"
#include "sensors.h"

#define STAT_BUFFER_SIZE 64

void watering_logic_init(void);
void watering_logic_cycle(sensor_data_t d);

#endif // WATERING_LOGIC_H
