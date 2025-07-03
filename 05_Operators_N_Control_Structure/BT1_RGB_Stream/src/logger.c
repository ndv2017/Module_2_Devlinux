#include "logger.h"
#include <time.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

static log_level_t current_level = LOG_INFO;
static FILE* log_file = NULL;

static const char* level_strings[] = {
    "EMERGENCY", "ALERT", "CRITICAL", "ERROR",
    "WARNING", "NOTICE", "INFO", "DEBUG"
};

static void get_timestamp(char* buffer, size_t size) {
    time_t now = time(NULL);
    struct tm* local = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", local);
}

void logger_set_level(log_level_t level) {
    current_level = level;
}

int logger_init(log_level_t level, const char* file_path) {
    logger_set_level(level);

    if (file_path) {
        log_file = fopen(file_path, "a");
        if (!log_file) {
            fprintf(stderr, "[LOGGER] Failed to open log file: %s\n", file_path);
            return -1;
        }
    }

    return 0;
}

void logger_log(log_level_t level, const char* file, int line, const char* format, ...) {
    char timestamp[MAX_BUF_TIMESTAMP];
    char message[MAX_BUF_MESSAGE];
    char final_output[MAX_BUF_FINAL_OUTPUT];
    va_list args;
    FILE* stream;

    if (level > current_level) return;

    get_timestamp(timestamp, sizeof(timestamp));

    va_start(args, format);
    vsnprintf(message, MAX_BUF_MESSAGE, format, args);
    va_end(args);

    snprintf(final_output, MAX_BUF_FINAL_OUTPUT, "[%s] [%s] [%s:%d] - %s\n",
             timestamp, level_strings[level], file, line, message);

    // Output to console
    stream = (level <= LOG_ERROR) ? stderr : stdout;
    fprintf(stream, "%s", final_output);
    fflush(stream);

    // Write to log file (optional)
    if (log_file) {
        fprintf(log_file, "%s", final_output);
        fflush(log_file);
    }
}

void logger_close(void) {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
}
