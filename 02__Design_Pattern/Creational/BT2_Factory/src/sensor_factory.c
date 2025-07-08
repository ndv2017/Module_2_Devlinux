#include <stdlib.h>
#include "sensor_factory.h"

sensor_t* create_sensor(sensor_type_t type) {
    switch (type) {
        case SENSOR_TEMPERATURE: return create_temperature_sensor();
        case SENSOR_HUMIDITY:    return create_humidity_sensor();
        case SENSOR_LIGHT:       return create_light_sensor();
        default:                 return NULL;
    }
}
