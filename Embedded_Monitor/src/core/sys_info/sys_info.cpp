#include "sys_info.h"

#include <fstream>
#include <sstream>
#include <ctime>
#include <unistd.h>
#include <sys/utsname.h>
#include <cstring>

sys_info::sys_info()
    : uptime_seconds(0.0f), load_1min(0.0f), load_5min(0.0f), load_15min(0.0f) {}

void sys_info::update() {
    parse_proc_uptime();
    parse_proc_loadavg();
    get_kernel_info();
    get_local_time();
}

void sys_info::parse_proc_uptime() {
    std::ifstream file(PROC_UPTIME_PATH);
    file >> uptime_seconds;
}
void sys_info::parse_proc_loadavg() {
    std::ifstream file(PROC_LOADAVG_PATH);
    file >> load_1min >> load_5min >> load_15min;
}

void sys_info::get_kernel_info() {
    struct utsname buffer;

    if (!uname(&buffer))
        kernel_version = std::string(buffer.release);
    else {
        logger_adapter::log(LOG_ERROR, "Failed to get kernel version: " + std::string(strerror(errno)));
        kernel_version = "unknown";
    }
}

void sys_info::get_local_time() {
    time_t now = time(nullptr);
    struct tm* tm_local = localtime(&now);
    char time_buffer[LOCAL_TIME_BUFFER_SIZE];

    if (strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_local) == 0) {
        logger_adapter::log(LOG_ERROR, "Failed to format local time");
        local_time_str = "unknown";
    }
    else
        local_time_str = std::string(time_buffer);
}

float sys_info::get_uptime_seconds() const {
    return uptime_seconds;
}

std::string sys_info::get_load_average() const {
    std::ostringstream oss;
    oss << "1min: " << load_1min << ", 5min: " << load_5min << ", 15min: " << load_15min;
    return oss.str();
}

std::string sys_info::get_kernel_version() const {
    return kernel_version;
}

std::string sys_info::get_local_time_string() const {
    return local_time_str;
}
