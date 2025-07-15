#include "led_driver.h"
#include "logger.h"

static uint32_t* p_led_buffer = NULL;
static size_t led_pixel_count = 0;
static uint32_t u32_color = 0;

int led_init(size_t num_pixels) {
    if (num_pixels <= 0) {
        log_message(LOG_ERROR, "Invalid number of pixels: %zu", num_pixels);
        return -1;
    }

    p_led_buffer = (uint32_t *)malloc(num_pixels * sizeof(uint32_t));
    if (!p_led_buffer) {
        log_message(LOG_ERROR, "Failed to allocate memory for LED buffer");
        return -1;
    }

    memset(p_led_buffer, 0, num_pixels * sizeof(uint32_t));
    led_pixel_count = num_pixels;
    log_message(LOG_INFO, "LED strip initialized with %zu pixels", num_pixels);

    return 0;
}

void led_shutdown(void) {
    if (p_led_buffer){
        free(p_led_buffer);
        p_led_buffer = NULL;
        log_message(LOG_INFO, "LED strip shutdown and memory freed");
    }

    led_pixel_count = 0;
}

void led_set_pixel_color(size_t index, uint8_t u8_r, uint8_t u8_g, uint8_t u8_b) {
    if (!p_led_buffer || index >= led_pixel_count){
        log_message(LOG_ERROR, "Attempt to set color for invalid pixel index: %zu", index);
        return;
    }

    u32_color = ((uint32_t)u8_g << 16) | ((uint32_t)u8_r << 8) | (uint32_t)u8_b;
    p_led_buffer[index] = u32_color;
    log_message(LOG_DEBUG, "Set pixel %zu color to R:%d G:%d B:%d", index, u8_r, u8_g, u8_b);
}

void led_fill(uint8_t u8_r, uint8_t u8_g, uint8_t u8_b) {
    if (!p_led_buffer) {
        log_message(LOG_ERROR, "LED buffer not initialized");
        return;
    }

    u32_color = ((uint32_t)u8_g << 16) | ((uint32_t)u8_r << 8) | (uint32_t)u8_b;
    for (size_t i = 0; i < led_pixel_count; i++)
        p_led_buffer[i] = u32_color;

    log_message(LOG_INFO, "Filled LED strip with color R:%d G:%d B:%d", u8_r, u8_g, u8_b);
}

void led_clear(void) {
    led_fill(0, 0, 0);
    log_message(LOG_INFO, "Cleared LED strip to black");
}

const uint32_t* led_get_buffer(void) {
    if (!p_led_buffer) {
        log_message(LOG_ERROR, "LED buffer not initialized");
        return NULL;
    }

    return p_led_buffer;
}

size_t led_get_pixel_count(void) {
    return led_pixel_count;
}
