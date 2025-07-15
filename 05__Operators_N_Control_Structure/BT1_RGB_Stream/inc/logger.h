#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

#define MAX_BUF_TIMESTAMP       32
#define MAX_BUF_MESSAGE         1024
#define MAX_BUF_FINAL_OUTPUT    1200

#define log_message(level, format, ...) \
    logger_log(level, __FILE__, __LINE__, format, ##__VA_ARGS__)

typedef enum {
    LOG_EMERGENCY = 0,
    LOG_ALERT,
    LOG_CRITICAL,
    LOG_ERROR,
    LOG_WARNING,
    LOG_NOTICE,
    LOG_INFO,
    LOG_DEBUG
} log_level_t;

int logger_init(log_level_t level, const char* file_path); // Pass NULL if no file output needed
void logger_set_level(log_level_t level);
void logger_log(log_level_t level, const char* file, int line, const char* format, ...);
void logger_close(void);

#endif // LOGGER_H
