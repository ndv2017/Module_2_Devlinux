#ifndef DOOR_SENSOR_H
#define DOOR_SENSOR_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "observer.h"

typedef struct {
    publisher_t base;
    bool is_opened;
    const char* location;
} door_sensor_t;

door_sensor_t* door_sensor_create(const char* location);
void door_sensor_trigger_event(door_sensor_t* sensor, bool new_state);
void door_sensor_destroy(door_sensor_t* sensor);

#endif // DOOR_SENSOR_H
