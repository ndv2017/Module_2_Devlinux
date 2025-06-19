#ifndef SENSORS_H
#define SENSORS_H

#include <stdint.h>

typedef struct {
    uint8_t moisture;
    float temperature;
} sensor_data_t;

void sensors_init(void);
sensor_data_t sensors_read(void);

#endif // SENSORS_H
