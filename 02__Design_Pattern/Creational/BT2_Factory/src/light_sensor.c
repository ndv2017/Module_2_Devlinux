#include <stdlib.h>
#include <stdio.h>
#include "sensor.h"

static void light_sensor_init(void) {
    printf("Light sensor initialized.\n");
}

static float light_sensor_read(void) {
    return 800.0f;
}

sensor_t* create_light_sensor(void) {
    sensor_t* sensor = (sensor_t*)malloc(sizeof(sensor_t));
    if (sensor) {
        sensor->init = light_sensor_init;
        sensor->read_data = light_sensor_read;
    }
    return sensor;
}
