#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

#define MOISTURE_MIN_INIT       30
#define MOISTURE_MAX_INIT       70
#define MAX_WATERING_MS_INIT    10000
#define SENSOR_CYCLE_MS_INIT    2000

typedef enum {
    MODE_AUTO,
    MODE_MANUAL
} system_mode_t;

typedef enum {
    PUMP_OFF,
    PUMP_ON
} pump_state_t;

typedef enum {
    LED_NORMAL,
    LED_WATERING,
    LED_LOW_MOISTURE_ALERT,
    LED_ERROR
} led_status_t;

typedef struct {
    uint8_t moisture_min;
    uint8_t moisture_max;
    uint32_t max_watering_ms;
    uint32_t sensor_cycle_ms;
    system_mode_t mode;
    pump_state_t pump;
    led_status_t led_status;
} system_config_t;

#endif // CONFIG_H
