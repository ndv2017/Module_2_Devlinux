#ifndef SYSTEM_MONITOR_H
#define SYSTEM_MONITOR_H

#include "cpu_stats.h"

class system_monitor {
public:
    system_monitor();

    void update();  // Refresh all data (for now: CPU only)

    const cpu_stats& get_cpu_stats() const;

private:
    cpu_stats cpu;
};

#endif  // SYSTEM_MONITOR_H
