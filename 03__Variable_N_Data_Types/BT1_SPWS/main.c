#include <stdio.h>
#include <unistd.h>
#include "config.h"
#include "sensors.h"
#include "actuators.h"
#include "buttons.h"
#include "watering_logic.h"

void init_system(void) {
    sensors_init();
    actuators_init();
    buttons_init();
    watering_logic_init();
}

int main(void) {
    sensor_data_t sensor_data;
    init_system();

    printf("[SPWS] Starting control loop\n");
    while (1) {
        printf("---------------------------------------------\n");
        sensor_data = sensors_read();
        watering_logic_cycle(sensor_data);
        usleep(1000000); // 1 second delay for simulation
    }

    return 0;
}
