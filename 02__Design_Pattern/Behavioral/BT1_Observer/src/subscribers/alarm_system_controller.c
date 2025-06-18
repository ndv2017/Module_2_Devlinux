#include <stdio.h>
#include <stdlib.h>
#include "alarm_system_controller.h"

void alarm_system_update(subscriber_t* self, const char* event) {
    printf("[AlarmSystem] Activating alarm due to event: %s\n", event);
}

subscriber_t* create_alarm_system_controller(void) {
    alarm_system_controller_t* ctrl = (alarm_system_controller_t*)malloc(sizeof(alarm_system_controller_t));
    ctrl->base.update = alarm_system_update;
    return (subscriber_t*)ctrl;
}
