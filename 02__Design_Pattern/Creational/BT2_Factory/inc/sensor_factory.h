#ifndef SENSOR_FACTORY_H
#define SENSOR_FACTORY_H

#include <stdlib.h>
#include "sensor.h"
#include "temperature_sensor.h"
#include "humidity_sensor.h"
#include "light_sensor.h"

typedef enum {
    SENSOR_TEMPERATURE,
    SENSOR_HUMIDITY,
    SENSOR_LIGHT
} sensor_type_t;

sensor_t* create_sensor(sensor_type_t type);

#endif
