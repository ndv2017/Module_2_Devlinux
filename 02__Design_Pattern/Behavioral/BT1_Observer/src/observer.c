#include <stdio.h>
#include "observer.h"

void publisher_init(publisher_t* pub) {
    pub->subscriber_count = 0;
    pub->subscribe = publisher_subscribe;
    pub->unsubscribe = publisher_unsubscribe;
    pub->notify = publisher_notify;
}

void publisher_subscribe(publisher_t* pub, subscriber_t* sub) {
    if (pub->subscriber_count < MAX_SUBSCRIBERS) {
        pub->subscribers[pub->subscriber_count++] = sub;
    }
}

void publisher_unsubscribe(publisher_t* pub, subscriber_t* sub) {
    for (int i = 0; i < pub->subscriber_count; ++i) {
        if (pub->subscribers[i] == sub) {
            for (int j = i; j < pub->subscriber_count - 1; ++j) {
                pub->subscribers[j] = pub->subscribers[j + 1];
            }
            pub->subscriber_count--;
            break;
        }
    }
}

void publisher_notify(publisher_t* pub, const char* event) {
    for (int i = 0; i < pub->subscriber_count; ++i) {
        pub->subscribers[i]->update(pub->subscribers[i], event);
    }
}
