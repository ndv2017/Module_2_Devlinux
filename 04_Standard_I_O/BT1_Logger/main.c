#include "logger.h"

#define PATH_TO_LOGGER "./log.txt"

int main(void) {
    // Initialize logger: minimum level INFO
    if (logger_init(LOG_INFO, PATH_TO_LOGGER) != 0) {
        return 1;
    }

    // Log messages at various levels
    log_message(LOG_DEBUG, "This is a debug message.");
    log_message(LOG_INFO, "System started.");
    log_message(LOG_WARNING, "Low battery level: %d%%", 20);
    log_message(LOG_ERROR, "Sensor disconnected!");
    log_message(LOG_CRITICAL, "Critical failure in module: %s", "Motor Controller");

    logger_set_level(LOG_DEBUG);  // Lower filter to allow debug
    log_message(LOG_DEBUG, "Now debugging is visible.");

    logger_close();
    return 0;
}
