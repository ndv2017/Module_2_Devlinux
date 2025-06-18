#ifndef MOBILE_APP_NOTIFIER_H
#define MOBILE_APP_NOTIFIER_H

#include "observer.h"

typedef struct {
    subscriber_t base;
    const char* user;
} mobile_app_notifier_t;

subscriber_t* create_mobile_app_notifier(const char* user);

#endif // MOBILE_APP_NOTIFIER_H
