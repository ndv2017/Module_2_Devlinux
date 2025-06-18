#ifndef SENSOR_H
#define SENSOR_H

typedef enum {
    SENSOR_TEMPERATURE,
    SENSOR_HUMIDITY,
    SENSOR_LIGHT
} sensor_type_t;

typedef struct sensor {
    void (*init)(void);
    float (*read_data)(void);
} sensor_t;

sensor_t* create_sensor(sensor_type_t type);

#endif // SENSOR_H
