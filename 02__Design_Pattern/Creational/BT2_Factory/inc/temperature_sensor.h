#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include <stdlib.h>
#include <stdio.h>
#include "sensor.h"

static void temperature_sensor_init(void);
static float temperature_sensor_read(void);
sensor_t* create_temperature_sensor(void);

#endif // TEMPERATURE_SENSOR_H
