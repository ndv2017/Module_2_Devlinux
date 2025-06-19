#include <stdio.h>
#include "actuators.h"

void actuators_init(void) {
    printf("[Actuators] Initialized (pump, LED)\n");
}

static led_status_t current_led = LED_NORMAL;

void turn_pump_on(void) {
    printf("[Pump] ON\n");
}

void turn_pump_off(void) {
    printf("[Pump] OFF\n");
}

void update_led(led_status_t status) {
    current_led = status;
    const char* names[] = {
        "NORMAL", "WATERING", "LOW_MOISTURE_ALERT", "ERROR"
    };
    printf("[LED] Status: %s\n", names[status]);
}

void notify_status(const char* msg) {
    printf("[Notify] %s\n", msg);
}
