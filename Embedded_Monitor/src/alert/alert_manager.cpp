#include "alert_manager.h"
#include "logger_adapter.h"

alert_manager::alert_manager() {}

void alert_manager::load_thresholds(const std::string& config_path) {
    if (!limits.load_from_file(config_path))
        logger_adapter::log(LOG_WARNING, "Failed to load thresholds config: " + config_path);
    else
        logger_adapter::log(LOG_INFO, "Thresholds loaded from: " + config_path);
}

void alert_manager::check(const system_monitor& snapshot) {
    const auto& cpu = snapshot.get_cpu_stats();
    const auto& mem = snapshot.get_mem_stats();
    const auto& disk = snapshot.get_disk_stats();
    const auto& net = snapshot.get_net_stats();
    const auto& sys = snapshot.get_sys_info();

    check_and_alert("cpu", 
        cpu.get_usage_percent() > limits.get_cpu_percent_max(),
        "CPU usage (" + std::to_string(cpu.get_usage_percent()) + "%) exceeded threshold (" +
        std::to_string(limits.get_cpu_percent_max()) + "%)");

    check_and_alert("ram", 
        mem.get_ram_usage_percent() > limits.get_ram_percent_max(),
        "RAM usage (" + std::to_string(mem.get_ram_usage_percent()) + "%) exceeded threshold (" +
        std::to_string(limits.get_ram_percent_max()) + "%)");

    check_and_alert("swap", 
        mem.get_swap_usage_percent() > limits.get_swap_percent_max(),
        "Swap usage (" + std::to_string(mem.get_swap_usage_percent()) + "%) exceeded threshold (" +
        std::to_string(limits.get_swap_percent_max()) + "%)");

    for (const auto& d : disk.get_usages()) {
        std::string id = "disk_" + d.mount_point;
        check_and_alert(id, 
            d.usage_percent > limits.get_disk_percent_max(),
            "Disk " + d.mount_point + " usage (" + std::to_string(d.usage_percent) + "%) exceeded threshold (" +
            std::to_string(limits.get_disk_percent_max()) + "%)");
    }

    for (const auto& [iface, speed] : net.get_speeds()) {
        check_and_alert("net_rx_" + iface,
            speed.rx_kbps > limits.get_net_rx_kbps_max(),
            "Net RX [" + iface + "] (" + std::to_string(speed.rx_kbps) + " KB/s) exceeded threshold (" +
            std::to_string(limits.get_net_rx_kbps_max()) + " KB/s)");

        check_and_alert("net_tx_" + iface,
            speed.tx_kbps > limits.get_net_tx_kbps_max(),
            "Net TX [" + iface + "] (" + std::to_string(speed.tx_kbps) + " KB/s) exceeded threshold (" +
            std::to_string(limits.get_net_tx_kbps_max()) + " KB/s)");
    }

    check_and_alert("load_1min",
        std::stof(sys.get_load_average().substr(0, sys.get_load_average().find(','))) > limits.get_load_1min_max(),
        "System load (1 min avg) exceeded threshold (" + std::to_string(limits.get_load_1min_max()) + ")");
}

bool alert_manager::check_and_alert(const std::string& key, bool condition, const std::string& message) {
    bool& already_alerting = alert_state[key];

    if (condition && !already_alerting) {
        logger_adapter::log(LOG_WARNING, message);
        already_alerting = true;
        return true;
    }
    else if (!condition && already_alerting) {
        already_alerting = false;
    }

    return false;
}
