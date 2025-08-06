#include "logger_adapter.h"

void logger_adapter::init(log_level_t level, const std::string& path) {
    logger_init(level, path.c_str());
}

void logger_adapter::log(log_level_t level, const std::string& msg) {
    logger_log(level, __FILE__, __LINE__, "%s", msg.c_str());
}

void logger_adapter::close() {
    logger_close();
}
