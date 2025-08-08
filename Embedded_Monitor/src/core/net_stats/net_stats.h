#ifndef NET_STATS_H
#define NET_STATS_H

#include <string>
#include <unordered_map>
#include <cstdint>

#define PROC_NET_DEV_PATH "/proc/net/dev"

struct net_io_data {
    uint64_t rx_bytes;
    uint64_t tx_bytes;
};

struct net_io_speed {
    float rx_kbps;
    float tx_kbps;
};

class net_stats {
public:
    net_stats();

    void update();

    std::unordered_map<std::string, net_io_speed> get_speeds() const;

private:
    std::unordered_map<std::string, net_io_data> prev_data;
    std::unordered_map<std::string, net_io_speed> current_speeds;

    void parse_proc_net_dev(std::unordered_map<std::string, net_io_data>& out);
};

#endif // NET_STATS_H
