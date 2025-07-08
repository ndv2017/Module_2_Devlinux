#ifndef SENSOR_H
#define SENSOR_H

typedef struct sensor {
    void (*init)(void);
    float (*read_data)(void);
} sensor_t;

#endif // SENSOR_H
