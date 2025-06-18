#include "door_sensor.h"

door_sensor_t* door_sensor_create(const char* location) {
    door_sensor_t* sensor = (door_sensor_t*)malloc(sizeof(door_sensor_t));

    if (sensor == NULL) {
        fprintf(stderr, "Memory allocation failed for door sensor.\n");
        return NULL;
    }

    publisher_init(&sensor->base);
    sensor->is_opened = false;
    sensor->location = location;
    return sensor;
}

void door_sensor_trigger_event(door_sensor_t* sensor, bool new_state) {
    sensor->is_opened = new_state;

    char full_event[256];
    snprintf(full_event, sizeof(full_event), "[%s] Door %s", sensor->location, sensor->is_opened ? "opened" : "closed");

    sensor->base.notify(&sensor->base, full_event);
}

void door_sensor_destroy(door_sensor_t* sensor) {
    free(sensor);
}
