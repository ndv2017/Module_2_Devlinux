#ifndef MEM_STATS_H
#define MEM_STATS_H

#include <cstdint>

#define PROC_MEMINFO_PATH "/proc/meminfo"

class mem_stats {
public:
    mem_stats();

    void update();

    float get_ram_usage_percent() const;
    float get_swap_usage_percent() const;

    uint64_t get_mem_total_kb() const;
    uint64_t get_mem_used_kb() const;
    uint64_t get_swap_total_kb() const;
    uint64_t get_swap_used_kb() const;

private:
    uint64_t mem_total_kb;
    uint64_t mem_free_kb;
    uint64_t mem_available_kb;
    uint64_t buffers_kb;
    uint64_t cached_kb;

    uint64_t swap_total_kb;
    uint64_t swap_free_kb;

    void parse_proc_meminfo();
};

#endif // MEM_STATS_H
