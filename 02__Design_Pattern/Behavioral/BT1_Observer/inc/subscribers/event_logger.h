#ifndef EVENT_LOGGER_H
#define EVENT_LOGGER_H

#include "observer.h"

typedef struct {
    subscriber_t base;
} event_logger_t;

subscriber_t* create_event_logger(void);

#endif // EVENT_LOGGER_H
