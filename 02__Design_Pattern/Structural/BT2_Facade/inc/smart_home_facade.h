#ifndef SMART_HOME_FACADE_H
#define SMART_HOME_FACADE_H

#include "lighting_system.h"
#include "security_system.h"
#include "hvac_system.h"

typedef struct {
    lighting_system_t* lighting;
    security_system_t* security;
    hvac_system_t* hvac;
} smart_home_facade_t;

smart_home_facade_t* smart_home_facade_create(void);
void activate_morning_routine(smart_home_facade_t* facade);
void activate_away_mode(smart_home_facade_t* facade);
void activate_movie_night(smart_home_facade_t* facade);

#endif // SMART_HOME_FACADE_H
