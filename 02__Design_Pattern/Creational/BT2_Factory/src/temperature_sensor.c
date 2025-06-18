#include <stdlib.h>
#include <stdio.h>
#include "sensor.h"

static void temperature_sensor_init(void) {
    printf("Temperature sensor initialized.\n");
}

static float temperature_sensor_read(void) {
    return 35.3f;
}

sensor_t* create_temperature_sensor(void) {
    sensor_t* sensor = (sensor_t*)malloc(sizeof(sensor_t));
    if (sensor) {
        sensor->init = temperature_sensor_init;
        sensor->read_data = temperature_sensor_read;
    }
    return sensor;
}
