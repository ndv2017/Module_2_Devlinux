#include <stdio.h>
#include "led_driver.h"
#include "logger.h"

#define NUM_PIXELS_INIT 10

static const uint32_t* p_led_buffer;

int init_led_strip(void);
void print_buffer_state(const uint32_t* p_buffer);

int main(void) {
    if (init_led_strip())
        return 1;

    p_led_buffer = led_get_buffer();

    // Check initial state (all 0)
    printf("\nInitial buffer state:\n");
    print_buffer_state(p_led_buffer);

    // Set specific pixel colors
    led_set_pixel_color(0, 255, 0, 0);      // Red
    led_set_pixel_color(4, 255, 255, 255);  // White
    led_set_pixel_color(9, 0, 0, 255);      // Blue

    // Print buffer state after setting colors
    printf("\nAfter setting individual pixels:\n");
    printf("\tPixel 0: 0x%08X\n", p_led_buffer[0]);
    printf("\tPixel 9: 0x%08X\n", p_led_buffer[9]);
    printf("\tPixel 4: 0x%08X\n", p_led_buffer[4]);
    printf("\n");

    // Fill entire strip with Green and print state
    led_fill(0, 255, 0);
    print_buffer_state(p_led_buffer);

    // Clean up
    led_shutdown();
    logger_close();
    return 0;
}

int init_led_strip(void) {
    if (logger_init(LOG_DEBUG, NULL)) {
        fprintf(stderr, "Logger initialization failed!\n");
        return 1;
    }

    if (led_init(NUM_PIXELS_INIT)) {
        log_message(LOG_CRITICAL, "LED strip initialization failed!");
        return 1;
    }

    return 0;
}

void print_buffer_state(const uint32_t* p_buffer) {
    for (size_t i = 0; i < led_get_pixel_count(); i++)
        printf("\tPixel %zu: 0x%08X\n", i, p_buffer[i]);

    printf("\n");
}
