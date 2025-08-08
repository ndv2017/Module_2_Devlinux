#ifndef LOGGER_ADAPTER_H
#define LOGGER_ADAPTER_H

extern "C" {
    #include "c_legacy/logger/logger.h"
}

#include <string>

class logger_adapter {
public:
    static void init(log_level_t level, const std::string& path);
    static void set_level(log_level_t level);
    static void log(log_level_t level, const std::string& msg);
    static void close();
};

#endif // LOGGER_ADAPTER_H
