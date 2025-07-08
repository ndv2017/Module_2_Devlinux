#include <stdlib.h>
#include <stdio.h>
#include "sensor.h"

static void light_sensor_init(void);
static float light_sensor_read(void);
sensor_t* create_light_sensor(void);
