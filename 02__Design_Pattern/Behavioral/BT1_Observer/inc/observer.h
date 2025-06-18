#ifndef OBSERVER_H
#define OBSERVER_H

#define MAX_SUBSCRIBERS 10

typedef struct subscriber {
    void (*update)(struct subscriber* self, const char* event);
} subscriber_t;

typedef struct publisher {
    subscriber_t* subscribers[MAX_SUBSCRIBERS];
    int subscriber_count;

    void (*subscribe)(struct publisher* self, subscriber_t* sub);
    void (*unsubscribe)(struct publisher* self, subscriber_t* sub);
    void (*notify)(struct publisher* self, const char* event);
} publisher_t;

void publisher_init(publisher_t* pub);
void publisher_subscribe(publisher_t* pub, subscriber_t* sub);
void publisher_unsubscribe(publisher_t* pub, subscriber_t* sub);
void publisher_notify(publisher_t* pub, const char* event);

#endif // OBSERVER_H
