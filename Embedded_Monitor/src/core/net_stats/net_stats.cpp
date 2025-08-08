#include "net_stats.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

net_stats::net_stats() {}

void net_stats::update() {
    std::unordered_map<std::string, net_io_data> current_data;
    parse_proc_net_dev(current_data);

    for (const auto& [iface, cur] : current_data) {
        const auto& prev = prev_data[iface];  // defaults to 0

        net_io_speed speed;
        speed.rx_kbps = static_cast<float>(cur.rx_bytes - prev.rx_bytes) / 1024.0f;
        speed.tx_kbps = static_cast<float>(cur.tx_bytes - prev.tx_bytes) / 1024.0f;

        current_speeds[iface] = speed;
    }

    prev_data = std::move(current_data);
}

std::unordered_map<std::string, net_io_speed> net_stats::get_speeds() const {
    return current_speeds;
}

void net_stats::parse_proc_net_dev(std::unordered_map<std::string, net_io_data>& out) {
    std::ifstream file(PROC_NET_DEV_PATH);
    std::string line;

    // Skip headers (first two lines)
    std::getline(file, line);
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string iface;
        std::getline(iss, iface, ':');  // Read up to the first colon -> name of the interface
        iface.erase(0, iface.find_first_not_of(" \t"));  // Clean leading whitespace

        net_io_data data;
        iss >> data.rx_bytes;
        // skip next 7 fields
        for (int i = 0; i < 7; ++i) {
            uint64_t skip;
            iss >> skip;
        }
        iss >> data.tx_bytes;

        out[iface] = data;
    }
}
