#include <iostream>
#include <thread>
#include <chrono>
#include <csignal>

#include "core/system_monitor.h"
#include "util/logger_adapter.h"
#include "alert/alert_manager.h"

#define LOG_FILE_PATH   "log/monitor.log"
#define CONFIG_PATH     "config/thresholds.conf"

bool is_running = true;

void signal_handler(int signal) {
    is_running = false;
    logger_adapter::log(LOG_INFO, "Caught signal " + std::to_string(signal) + ", exiting...");
}

int main() {
    std::signal(SIGINT, signal_handler);

    logger_adapter::init(LOG_INFO, LOG_FILE_PATH);
    logger_adapter::log(LOG_INFO, "System monitor started.");

    system_monitor monitor;
    alert_manager alerts;
    alerts.load_thresholds(CONFIG_PATH);

    while (is_running) {
        monitor.update();

        float cpu_usage = monitor.get_cpu_stats().get_usage_percent();
        float ram_usage = monitor.get_mem_stats().get_ram_usage_percent();
        float swap_usage = monitor.get_mem_stats().get_swap_usage_percent();
        const auto& disk_usages = monitor.get_disk_stats().get_usages();
        const auto& net = monitor.get_net_stats().get_speeds();
        const auto& sys_info = monitor.get_sys_info();
        alerts.check(monitor);

        std::cout << "===========================================================" << std::endl;

        // CPU stats
        std::cout << "CPU Usage: " << cpu_usage << " %" << std::endl;
        std::cout << std::endl;

        // Memory stats
        std::cout << "RAM Usage: " << ram_usage << " %" << std::endl;
        std::cout << "Swap Usage: " << swap_usage << " %" << std::endl;
        std::cout << std::endl;

        // Disk stats
        for (const auto& disk_usage : disk_usages) {
            std::string log_msg = "Disk " + disk_usage.mount_point + "\t-> Used: " + std::to_string(disk_usage.used_kb) +
                                " KB / " + std::to_string(disk_usage.total_kb) + " KB (" +
                                std::to_string(disk_usage.usage_percent) + " %)";

            std::cout << log_msg << std::endl;
        }
        std::cout << std::endl;

        // Network stats
        for (const auto& [iface, speed] : net) {
            std::string net_msg = "Net [" + iface + "]\t-> RX: " + std::to_string(speed.rx_kbps) +
                            " KB/s, TX: " + std::to_string(speed.tx_kbps) + " KB/s";

            std::cout << net_msg << std::endl;
        }
        std::cout << std::endl;

        // System info
        std::cout << "Uptime: " << sys_info.get_uptime_seconds() << " seconds" << std::endl;
        std::cout << "Load Average\t-> " << sys_info.get_load_average() << std::endl;
        std::cout << "Kernel Version: " << sys_info.get_kernel_version() << std::endl;
        std::cout << "Local Time: " << sys_info.get_local_time_string() << std::endl;
        std::cout << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    logger_adapter::log(LOG_INFO, "System monitor stopped.");
    logger_adapter::close();

    return 0;
}
