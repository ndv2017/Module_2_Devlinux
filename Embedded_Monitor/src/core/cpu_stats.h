#ifndef CPU_STATS_H
#define CPU_STATS_H

#include <vector>
#include <cstdint>

class cpu_stats {
public:
    cpu_stats();

    void update();  // Read /proc/stat and update usage

    float get_usage_percent() const;

private:
    uint64_t prev_idle_time;
    uint64_t prev_total_time;
    float usage_percent;

    void parse_proc_stat(uint64_t& idle_time, uint64_t& total_time);
};

#endif  // CPU_STATS_H
