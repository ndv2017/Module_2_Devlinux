#include <stdio.h>
#include "sensor_manager.h"

int main(void) {
    sensor_manager_t* sensor_manager_1 = get_sensor_manager_instance();
    sensor_manager_t* sensor_manager_2 = get_sensor_manager_instance();

    sensor_manager_1->collect_data();
    sensor_manager_2->upload_data();

    if (sensor_manager_1 == sensor_manager_2) {
        printf("--> Singleton verified: sensor_manager_1 and sensor_manager_2 are the same instance.\n");
    } else {
        printf("--> Singleton violated: sensor_manager_1 and sensor_manager_2 are different instances!\n");
    }

    return 0;
}
