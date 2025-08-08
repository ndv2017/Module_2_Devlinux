#include "mem_stats.h"
#include <fstream>
#include <sstream>
#include <string>

mem_stats::mem_stats()
    : mem_total_kb(0), mem_free_kb(0), mem_available_kb(0),
      buffers_kb(0), cached_kb(0),
      swap_total_kb(0), swap_free_kb(0) {}

void mem_stats::update() {
    parse_proc_meminfo();
}

void mem_stats::parse_proc_meminfo() {
    std::ifstream file(PROC_MEMINFO_PATH);
    std::string line, key;
    uint64_t value;
    std::string unit;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> key >> value >> unit;

        if (key == "MemTotal:")             mem_total_kb = value;
        else if (key == "MemFree:")         mem_free_kb = value;
        else if (key == "MemAvailable:")    mem_available_kb = value;
        else if (key == "Buffers:")         buffers_kb = value;
        else if (key == "Cached:")          cached_kb = value;
        else if (key == "SwapTotal:")       swap_total_kb = value;
        else if (key == "SwapFree:")        swap_free_kb = value;
    }
}

float mem_stats::get_ram_usage_percent() const {
    uint64_t used = mem_total_kb - mem_available_kb;
    return (mem_total_kb == 0) ? 0.0f : (float)used / mem_total_kb * 100.0f;
}

float mem_stats::get_swap_usage_percent() const {
    uint64_t used = swap_total_kb - swap_free_kb;
    return (swap_total_kb == 0) ? 0.0f : (float)used / swap_total_kb * 100.0f;
}

uint64_t mem_stats::get_mem_total_kb() const { return mem_total_kb; }
uint64_t mem_stats::get_mem_used_kb()  const { return mem_total_kb - mem_available_kb; }
uint64_t mem_stats::get_swap_total_kb() const { return swap_total_kb; }
uint64_t mem_stats::get_swap_used_kb()  const { return swap_total_kb - swap_free_kb; }
