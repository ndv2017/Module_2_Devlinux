#ifndef LIGHTING_SYSTEM_H
#define LIGHTING_SYSTEM_H

#include <stdint.h>

typedef struct {
    uint8_t brightness;
    uint8_t is_on;
} lighting_system_t;

lighting_system_t* lighting_system_create(void);
void lighting_system_turn_on(lighting_system_t* lighting);
void lighting_system_turn_off(lighting_system_t* lighting);
void lighting_system_set_brightness(lighting_system_t* lighting, uint8_t brightness);

#endif // LIGHTING_SYSTEM_H
