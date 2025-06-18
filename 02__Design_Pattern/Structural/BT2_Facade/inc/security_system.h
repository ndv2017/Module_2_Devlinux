#ifndef SECURITY_SYSTEM_H
#define SECURITY_SYSTEM_H

typedef enum {
    SECURITY_MODE_OFF,
    SECURITY_MODE_PARTIAL,
    SECURITY_MODE_FULL
} security_mode_t;

typedef struct {
    security_mode_t mode;
} security_system_t;

security_system_t* security_system_create(void);
void security_system_enable_full(security_system_t* security);
void security_system_enable_partial(security_system_t* security);
void security_system_disable(security_system_t* security);

#endif // SECURITY_SYSTEM_H
