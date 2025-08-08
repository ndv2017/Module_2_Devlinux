#include "cpu_stats.h"

#include <fstream>
#include <sstream>
#include <string>

cpu_stats::cpu_stats()
    : prev_idle_time(0), prev_total_time(0), usage_percent(0.0f) {}

void cpu_stats::update() {
    uint64_t idle_time = 0;
    uint64_t total_time = 0;

    parse_proc_stat(idle_time, total_time);

    uint64_t delta_idle = idle_time - prev_idle_time;
    uint64_t delta_total = total_time - prev_total_time;

    if (delta_total > 0) {
        usage_percent = 1.0f - static_cast<float>(delta_idle) / delta_total;
        usage_percent *= 100.0f;  // Convert to %
    }

    prev_idle_time = idle_time;
    prev_total_time = total_time;
}

float cpu_stats::get_usage_percent() const {
    return usage_percent;
}

void cpu_stats::parse_proc_stat(uint64_t& idle_time, uint64_t& total_time) {
    std::ifstream stat_file(PROC_STAT_PATH);
    std::string line;

    if (std::getline(stat_file, line)) {
        std::istringstream iss(line);
        std::string cpu_label;
        iss >> cpu_label;  // "cpu"

        uint64_t val = 0;
        int field_idx = 0;

        while (iss >> val) {
            total_time += val;
            if (field_idx == 3) {  // collum 4 is idle field
                idle_time = val;
            }

            ++field_idx;
        }
    }
}
