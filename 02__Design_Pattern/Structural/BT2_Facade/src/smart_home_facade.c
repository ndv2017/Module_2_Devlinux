#include <stdlib.h>
#include "smart_home_facade.h"

smart_home_facade_t* smart_home_facade_create(void) {
    smart_home_facade_t* facade = (smart_home_facade_t*)malloc(sizeof(smart_home_facade_t));
    facade->lighting = lighting_system_create();
    facade->security = security_system_create();
    facade->hvac = hvac_system_create();
    return facade;
}

void activate_morning_routine(smart_home_facade_t* facade) {
    lighting_system_turn_on(facade->lighting);
    lighting_system_set_brightness(facade->lighting, 75);
    security_system_enable_partial(facade->security);
    hvac_system_turn_on(facade->hvac);
    hvac_system_set_temperature(facade->hvac, 22.0f);
}

void activate_away_mode(smart_home_facade_t* facade) {
    lighting_system_turn_off(facade->lighting);
    security_system_enable_full(facade->security);
    hvac_system_turn_off(facade->hvac);
}

void activate_movie_night(smart_home_facade_t* facade) {
    lighting_system_turn_on(facade->lighting);
    lighting_system_set_brightness(facade->lighting, 20);
    security_system_enable_partial(facade->security);
    hvac_system_turn_on(facade->hvac);
    hvac_system_set_temperature(facade->hvac, 21.0f);
}
