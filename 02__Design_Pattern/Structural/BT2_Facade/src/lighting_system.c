#include <stdlib.h>
#include <stdio.h>
#include "lighting_system.h"

lighting_system_t* lighting_system_create(void) {
    lighting_system_t* system = (lighting_system_t*)malloc(sizeof(lighting_system_t));
    system->brightness = 0;
    system->is_on = 0;
    return system;
}

void lighting_system_turn_on(lighting_system_t* lighting) {
    lighting->is_on = 1;
    printf("Lighting: turned on.\n");
}

void lighting_system_turn_off(lighting_system_t* lighting) {
    lighting->is_on = 0;
    printf("Lighting: turned off.\n");
}

void lighting_system_set_brightness(lighting_system_t* lighting, uint8_t brightness) {
    lighting->brightness = brightness;
    printf("Lighting: brightness set to %u%%.\n", brightness);
}
