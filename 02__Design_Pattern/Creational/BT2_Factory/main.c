#include <stdio.h>
#include <stdlib.h>
#include "sensor.h"

int main(void) {
    sensor_t* temp_sensor = create_sensor(SENSOR_TEMPERATURE);
    if (temp_sensor != NULL) {
        temp_sensor->init();
        printf("Temperature: %.2f°C\n", temp_sensor->read_data());
        free(temp_sensor);
    }

    sensor_t* humidity_sensor = create_sensor(SENSOR_HUMIDITY);
    if (humidity_sensor != NULL) {
        humidity_sensor->init();
        printf("Humidity: %.2f%%\n", humidity_sensor->read_data());
        free(humidity_sensor);
    }

    sensor_t* light_sensor = create_sensor(SENSOR_LIGHT);
    if (light_sensor != NULL) {
        light_sensor->init();
        printf("Light Intensity: %.2f lux\n", light_sensor->read_data());
        free(light_sensor);
    }

    return 0;
}
