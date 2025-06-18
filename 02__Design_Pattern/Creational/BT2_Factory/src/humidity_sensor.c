#include <stdlib.h>
#include <stdio.h>
#include "sensor.h"

static void humidity_sensor_init(void) {
    printf("Humidity sensor initialized.\n");
}

static float humidity_sensor_read(void) {
    return 50.2f;
}

sensor_t* create_humidity_sensor(void) {
    sensor_t* sensor = (sensor_t*)malloc(sizeof(sensor_t));
    if (sensor) {
        sensor->init = humidity_sensor_init;
        sensor->read_data = humidity_sensor_read;
    }
    return sensor;
}
