#ifndef LED_DRIVER_H
#define LED_DRIVER_H

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h> // for memset

int led_init(size_t num_pixels);
void led_shutdown(void);

void led_set_pixel_color(size_t index, uint8_t u8_r, uint8_t u8_g, uint8_t u8_b);
void led_fill(uint8_t u8_r, uint8_t u8_g, uint8_t u8_b);
void led_clear(void);

const uint32_t* led_get_buffer(void);
size_t led_get_pixel_count(void);

#endif // LED_DRIVER_H
