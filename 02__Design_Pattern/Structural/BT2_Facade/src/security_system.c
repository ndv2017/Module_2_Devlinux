#include <stdlib.h>
#include <stdio.h>
#include "security_system.h"

security_system_t* security_system_create(void) {
    security_system_t* system = (security_system_t*)malloc(sizeof(security_system_t));
    system->mode = SECURITY_MODE_OFF;
    return system;
}

void security_system_enable_full(security_system_t* security) {
    security->mode = SECURITY_MODE_FULL;
    printf("Security: full mode enabled.\n");
}

void security_system_enable_partial(security_system_t* security) {
    security->mode = SECURITY_MODE_PARTIAL;
    printf("Security: partial mode enabled.\n");
}

void security_system_disable(security_system_t* security) {
    security->mode = SECURITY_MODE_OFF;
    printf("Security: disabled.\n");
}
