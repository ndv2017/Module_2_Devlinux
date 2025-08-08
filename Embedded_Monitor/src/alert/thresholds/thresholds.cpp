#include "thresholds.h"
#include <fstream>
#include <sstream>

thresholds::thresholds()
    : cpu_percent_max(CPU_PERCENT_MAX_DEFAULT),
      ram_percent_max(RAM_PERCENT_MAX_DEFAULT),
      swap_percent_max(SWAP_PERCENT_MAX_DEFAULT),
      disk_percent_max(DISK_PERCENT_MAX_DEFAULT),
      net_rx_kbps_max(NET_RX_KBPS_MAX_DEFAULT),
      net_tx_kbps_max(NET_TX_KBPS_MAX_DEFAULT),
      load_1min_max(LOAD_1MIN_MAX_DEFAULT) {}

bool thresholds::load_from_file(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open())
        return false;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        float value;

        if (line.empty() || line[0] == '#')
            continue;

        if (iss >> key >> value) {
            if (key == "cpu_percent_max")       cpu_percent_max = value;
            else if (key == "ram_percent_max")  ram_percent_max = value;
            else if (key == "swap_percent_max") swap_percent_max = value;
            else if (key == "disk_percent_max") disk_percent_max = value;
            else if (key == "net_rx_kbps_max")  net_rx_kbps_max = value;
            else if (key == "net_tx_kbps_max")  net_tx_kbps_max = value;
            else if (key == "load_1min_max")    load_1min_max = value;
        }
    }

    return true;
}

float thresholds::get_cpu_percent_max() const { return cpu_percent_max; }
float thresholds::get_ram_percent_max() const { return ram_percent_max; }
float thresholds::get_swap_percent_max() const { return swap_percent_max; }
float thresholds::get_disk_percent_max() const { return disk_percent_max; }
float thresholds::get_net_rx_kbps_max() const { return net_rx_kbps_max; }
float thresholds::get_net_tx_kbps_max() const { return net_tx_kbps_max; }
float thresholds::get_load_1min_max() const { return load_1min_max; }
