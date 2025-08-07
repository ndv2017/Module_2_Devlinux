#ifndef THRESHOLDS_H
#define THRESHOLDS_H

#include <string>

#define CPU_PERCENT_MAX_DEFAULT 90.0f
#define RAM_PERCENT_MAX_DEFAULT 90.0f
#define SWAP_PERCENT_MAX_DEFAULT 90.0f
#define DISK_PERCENT_MAX_DEFAULT 90.0f
#define NET_RX_KBPS_MAX_DEFAULT 1024.0f
#define NET_TX_KBPS_MAX_DEFAULT 1024.0f
#define LOAD_1MIN_MAX_DEFAULT 2.0f

class thresholds {
public:
    thresholds();

    bool load_from_file(const std::string& path);

    float get_cpu_percent_max() const;
    float get_ram_percent_max() const;
    float get_swap_percent_max() const;
    float get_disk_percent_max() const;
    float get_net_rx_kbps_max() const;
    float get_net_tx_kbps_max() const;
    float get_load_1min_max() const;

private:
    float cpu_percent_max;
    float ram_percent_max; 
    float swap_percent_max; 
    float disk_percent_max; 
    float net_rx_kbps_max; 
    float net_tx_kbps_max; 
    float load_1min_max; 
};

#endif // THRESHOLDS_H
