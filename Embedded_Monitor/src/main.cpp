#include <iostream>
#include <thread>
#include <chrono>
#include <csignal>

#include "core/system_monitor.h"
#include "util/logger_adapter.h"

#define LOG_FILE_PATH "log/monitor.log"

bool running = true;

void signal_handler(int signal) {
    running = false;
    logger_adapter::log(LOG_INFO, "Caught signal " + std::to_string(signal) + ", exiting...");
}

int main() {
    std::signal(SIGINT, signal_handler);

    logger_adapter::init(LOG_INFO, LOG_FILE_PATH);
    logger_adapter::log(LOG_INFO, "System monitor started.");

    system_monitor monitor;

    while (running) {
        monitor.update();
        float cpu_usage = monitor.get_cpu_stats().get_usage_percent();
        float ram_usage = monitor.get_mem_stats().get_ram_usage_percent();
        float swap_usage = monitor.get_mem_stats().get_swap_usage_percent();
        const auto& disk_usages = monitor.get_disk_stats().get_usages();
        const auto& net = monitor.get_net_stats().get_speeds();

        std::cout << "===========================================================" << std::endl;
        std::cout << "CPU Usage: " << cpu_usage << " %" << std::endl;
        // logger_adapter::log(LOG_INFO, "CPU Usage: " + std::to_string(usage) + " %");

        std::cout << "RAM Usage: " << ram_usage << " %" << std::endl;
        // logger_adapter::log(LOG_INFO, "RAM Usage: " + std::to_string(ram_usage) + " %");

        std::cout << "Swap Usage: " << swap_usage << " %" << std::endl;
        // logger_adapter::log(LOG_INFO, "Swap Usage: " + std::to_string(swap_usage) + " %");

        for (const auto& disk_usage : disk_usages) {
            std::string log_msg = "Disk " + disk_usage.mount_point + " - Used: " + std::to_string(disk_usage.used_kb) +
                                " KB / " + std::to_string(disk_usage.total_kb) + " KB (" +
                                std::to_string(disk_usage.usage_percent) + " %)";

            std::cout << log_msg << std::endl;
            // logger_adapter::log(LOG_INFO, log_msg);
        }

        for (const auto& [iface, speed] : net) {
            std::string net_msg = "Net [" + iface + "] - RX: " + std::to_string(speed.rx_kbps) +
                            " KB/s, TX: " + std::to_string(speed.tx_kbps) + " KB/s";

            std::cout << net_msg << std::endl;
            // logger_adapter::log(LOG_INFO, net_msg);
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    logger_adapter::log(LOG_INFO, "System monitor stopped.");
    logger_adapter::close();

    return 0;
}
