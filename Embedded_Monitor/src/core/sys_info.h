#ifndef SYS_INFO_H
#define SYS_INFO_H

#include <string>
#include <logger_adapter.h>

#define PROC_UPTIME_PATH "/proc/uptime"
#define PROC_LOADAVG_PATH "/proc/loadavg"

#define LOCAL_TIME_BUFFER_SIZE 64

class sys_info {
public:
    sys_info();

    void update();

    float get_uptime_seconds() const;
    std::string get_load_average() const;
    std::string get_kernel_version() const;
    std::string get_local_time_string() const;

private:
    float uptime_seconds;
    float load_1min, load_5min, load_15min;
    std::string kernel_version;
    std::string local_time_str;

    void parse_proc_uptime();
    void parse_proc_loadavg();
    void get_kernel_info();
    void get_local_time();
};

#endif // SYS_INFO_H
