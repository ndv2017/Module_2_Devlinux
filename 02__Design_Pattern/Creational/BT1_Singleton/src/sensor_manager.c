#include <stdio.h>
#include <stdlib.h>
#include "sensor_manager.h"

static void collect_data_implementation(void);
static void upload_data_implementation(void);

static sensor_manager_t* sensor_manager_instance = NULL;

sensor_manager_t* get_sensor_manager_instance(void) {
    if (sensor_manager_instance == NULL) {
        sensor_manager_instance = (sensor_manager_t*)malloc(sizeof(sensor_manager_t));
        if (sensor_manager_instance != NULL) {
            sensor_manager_instance->collect_data = collect_data_implementation;
            sensor_manager_instance->upload_data = upload_data_implementation;
        }
    }

    return sensor_manager_instance;
}

static void collect_data_implementation(void) {
    printf("Collecting data from sensors...\n");
}

static void upload_data_implementation(void) {
    printf("Uploading data to database...\n");
}
