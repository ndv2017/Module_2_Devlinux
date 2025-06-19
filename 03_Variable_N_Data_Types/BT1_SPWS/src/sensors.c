#include <stdlib.h>
#include <stdio.h>
#include "sensors.h"

void sensors_init(void) {
    printf("[Sensors] Initialized (simulated)\n");
}

sensor_data_t sensors_read(void) {
    // Simulate sensor data reading
    sensor_data_t sensor_data = {
        .moisture = rand() % 101,
        .temperature = 15.0f + (rand() % 2000) / 100.0f
    };

    printf("[Sensors] Moisture=%u%%, Temp=%.1f°C\n", sensor_data.moisture, sensor_data.temperature);
    return sensor_data;
}
