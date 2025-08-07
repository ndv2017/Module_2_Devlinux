#include "system_monitor.h"

system_monitor::system_monitor() {
    // Constructor – may initialize members if needed later
}

void system_monitor::update() {
    cpu.update();
    mem.update();
    disk.update();
    net.update();
    sys.update();
}

const cpu_stats& system_monitor::get_cpu_stats() const {
    return cpu;
}

const mem_stats& system_monitor::get_mem_stats() const {
    return mem;
}

const disk_stats& system_monitor::get_disk_stats() const {
    return disk;
}

const net_stats& system_monitor::get_net_stats() const {
    return net;
}

const sys_info& system_monitor::get_sys_info() const {
    return sys;
}
