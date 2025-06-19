#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include "watering_logic.h"
#include "actuators.h"
#include "buttons.h"

static system_config_t sys_config;
static uint32_t watering_elapsed_ms;
static uint32_t last_sensor_time_ms;

void watering_logic_init(void) {
    sys_config.moisture_min = MOISTURE_MIN_INIT;
    sys_config.moisture_max = MOISTURE_MAX_INIT;
    sys_config.max_watering_ms = MAX_WATERING_MS_INIT;
    sys_config.sensor_cycle_ms = SENSOR_CYCLE_MS_INIT;
    sys_config.mode = MODE_AUTO;
    sys_config.pump = PUMP_OFF;
    sys_config.led_status = LED_NORMAL;
    watering_elapsed_ms = 0;
    last_sensor_time_ms = 0;
}

static uint32_t get_time_ms(void) {
    return (uint32_t)clock() * 1000 / CLOCKS_PER_SEC;
}

void watering_logic_cycle(sensor_data_t d) {
    uint32_t now = get_time_ms();

    if (button1_pressed()) {
        sys_config.mode = (sys_config.mode == MODE_AUTO ? MODE_MANUAL : MODE_AUTO);
        if (sys_config.mode == MODE_MANUAL && sys_config.pump == PUMP_ON) {
            sys_config.pump = PUMP_OFF;
            turn_pump_off();
        }
        char buf[64];
        snprintf(buf, sizeof(buf), "Mode toggled to %s",
                 sys_config.mode == MODE_AUTO ? "AUTO" : "MANUAL");
        notify_status(buf);
    }

    if (sys_config.mode == MODE_MANUAL && button2_pressed()) {
        if (sys_config.pump == PUMP_OFF) {
            turn_pump_on();
            sys_config.pump = PUMP_ON;
            notify_status("Manual watering started");
            // watering for fixed duration simulated below
            watering_elapsed_ms = 0;
        }
    }

    if (sys_config.mode == MODE_AUTO && now - last_sensor_time_ms >= sys_config.sensor_cycle_ms) {
        last_sensor_time_ms = now;
        if (sys_config.pump == PUMP_OFF && d.moisture < sys_config.moisture_min) {
            turn_pump_on();
            sys_config.pump = PUMP_ON;
            notify_status("Auto watering started");
            watering_elapsed_ms = 0;
        }
    }

    if (sys_config.pump == PUMP_ON) {
        watering_elapsed_ms += 100; // next delay
        if ((sys_config.mode == MODE_AUTO && (d.moisture >= sys_config.moisture_max || watering_elapsed_ms >= sys_config.max_watering_ms)) ||
            (sys_config.mode == MODE_MANUAL && watering_elapsed_ms >= sys_config.max_watering_ms)) {
            turn_pump_off();
            sys_config.pump = PUMP_OFF;
            notify_status("Watering stopped");
        }
    }

    if (sys_config.pump == PUMP_ON) {
        sys_config.led_status = LED_WATERING;
    } else if (d.moisture < sys_config.moisture_min) {
        sys_config.led_status = LED_LOW_MOISTURE_ALERT;
    } else {
        sys_config.led_status = LED_NORMAL;
    }
    update_led(sys_config.led_status);

    char stat[64];
    snprintf(stat, sizeof(stat), "Moisture=%u%%, Mode=%s, Pump=%s",
             d.moisture,
             sys_config.mode == MODE_AUTO ? "AUTO" : "MANUAL",
             sys_config.pump == PUMP_ON ? "ON" : "OFF");
    notify_status(stat);
}
