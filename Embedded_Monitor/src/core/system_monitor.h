#ifndef SYSTEM_MONITOR_H
#define SYSTEM_MONITOR_H

#include "cpu_stats.h"
#include "mem_stats.h"
#include "disk_stats.h"
#include "net_stats.h"
#include "sys_info.h"

class system_monitor {
public:
    system_monitor();

    void update();  // Refresh all data (for now: CPU only)

    const cpu_stats& get_cpu_stats() const;
    const mem_stats& get_mem_stats() const;
    const disk_stats& get_disk_stats() const;
    const net_stats& get_net_stats() const;
    const sys_info& get_sys_info() const;

private:
    cpu_stats cpu;
    mem_stats mem;
    disk_stats disk;
    net_stats net;
    sys_info sys;
};

#endif  // SYSTEM_MONITOR_H
