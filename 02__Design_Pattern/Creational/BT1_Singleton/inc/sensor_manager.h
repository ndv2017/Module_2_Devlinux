#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

typedef struct {
    int id;
    float data;
} sensor_node_t;

typedef struct {
    void (*collect_data)(void);
    void (*upload_data)(void);
} sensor_manager_t;

sensor_manager_t* get_sensor_manager_instance(void);

#endif // SENSOR_MANAGER_H
