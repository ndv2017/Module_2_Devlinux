#include <stdio.h>
#include <stdlib.h>
#include "door_sensor.h"
#include "mobile_app_notifier.h"
#include "alarm_system_controller.h"
#include "event_logger.h"

int main(void) {
    // Create the door sensor (publisher)
    door_sensor_t* main_door = door_sensor_create("Main Entrance");

    // Create subscribers
    subscriber_t* mobile_app_1 = create_mobile_app_notifier("Viet Nguyen Duc");
    subscriber_t* mobile_app_2 = create_mobile_app_notifier("Devlinux");
    subscriber_t* alarm_system = create_alarm_system_controller();
    subscriber_t* logger = create_event_logger();

    // Subscribe the mobile app, alarm system, and logger to the door sensor
    main_door->base.subscribe(&main_door->base, mobile_app_1);
    main_door->base.subscribe(&main_door->base, mobile_app_2);
    main_door->base.subscribe(&main_door->base, alarm_system);
    main_door->base.subscribe(&main_door->base, logger);

    // Simulate door opened
    printf("---> Door opened event\n");
    door_sensor_trigger_event(main_door, true);

    // Simulate door closed
    printf("\n--->Door closed event\n");
    door_sensor_trigger_event(main_door, false);

    // Clean up
    free(mobile_app_1);
    free(mobile_app_2);
    free(alarm_system);
    free(logger);
    door_sensor_destroy(main_door);

    return 0;
}
