#include "system_monitor.h"

system_monitor::system_monitor() {
    // Constructor – may initialize members if needed later
}

void system_monitor::update() {
    cpu.update();  // Later: mem.update(), disk.update(), etc.
}

const cpu_stats& system_monitor::get_cpu_stats() const {
    return cpu;
}
