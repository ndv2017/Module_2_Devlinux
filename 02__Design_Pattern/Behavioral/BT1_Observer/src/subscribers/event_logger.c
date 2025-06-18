#include <stdio.h>
#include <stdlib.h>
#include "event_logger.h"

void event_logger_update(subscriber_t* self, const char* event) {
    printf("[EventLogger] Event recorded: %s\n", event);
}

subscriber_t* create_event_logger(void) {
    event_logger_t* logger = (event_logger_t*)malloc(sizeof(event_logger_t));
    logger->base.update = event_logger_update;
    return (subscriber_t*)logger;
}
