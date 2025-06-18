#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

typedef struct {
    int id;
    float data;
} SensorNode;

typedef struct {
    void (*collect_data)(void);
    void (*upload_data)(void);
} SensorManager;

SensorManager* get_sensor_manager_instance(void);

#endif // SENSOR_MANAGER_H
