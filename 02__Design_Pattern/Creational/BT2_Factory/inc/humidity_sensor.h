#ifndef HUMIDITY_SENSOR_H
#define HUMIDITY_SENSOR_H

#include <stdlib.h>
#include <stdio.h>
#include "sensor.h"

static void humidity_sensor_init(void);
static float humidity_sensor_read(void);
sensor_t* create_humidity_sensor(void);

#endif // HUMIDITY_SENSOR_H
