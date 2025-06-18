#ifndef HVAC_SYSTEM_H
#define HVAC_SYSTEM_H

typedef struct {
    float temperature;
    uint8_t is_on;
} hvac_system_t;

hvac_system_t* hvac_system_create(void);
void hvac_system_turn_on(hvac_system_t* hvac);
void hvac_system_turn_off(hvac_system_t* hvac);
void hvac_system_set_temperature(hvac_system_t* hvac, float temperature);

#endif // HVAC_SYSTEM_H
