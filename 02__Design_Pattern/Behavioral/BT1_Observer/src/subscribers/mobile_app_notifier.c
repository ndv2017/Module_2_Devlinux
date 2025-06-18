#include <stdio.h>
#include <stdlib.h>
#include "mobile_app_notifier.h"

void mobile_app_update(subscriber_t* self, const char* event) {
    mobile_app_notifier_t* notifier = (mobile_app_notifier_t*)self;
    printf("[MobileApp] User '%s' received event: %s\n", notifier->user, event);
}

subscriber_t* create_mobile_app_notifier(const char* user) {
    mobile_app_notifier_t* notifier = (mobile_app_notifier_t*)malloc(sizeof(mobile_app_notifier_t));
    notifier->base.update = mobile_app_update;
    notifier->user = user;
    return (subscriber_t*)notifier;
}
