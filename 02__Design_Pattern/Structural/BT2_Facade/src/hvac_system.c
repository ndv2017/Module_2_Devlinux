#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "hvac_system.h"

hvac_system_t* hvac_system_create(void) {
    hvac_system_t* system = (hvac_system_t*)malloc(sizeof(hvac_system_t));
    system->temperature = 24.0f;
    system->is_on = 0;
    return system;
}

void hvac_system_turn_on(hvac_system_t* hvac) {
    hvac->is_on = 1;
    printf("HVAC: turned on.\n");
}

void hvac_system_turn_off(hvac_system_t* hvac) {
    hvac->is_on = 0;
    printf("HVAC: turned off.\n");
}

void hvac_system_set_temperature(hvac_system_t* hvac, float temperature) {
    hvac->temperature = temperature;
    printf("HVAC: temperature set to %.1f°C.\n", temperature);
}
