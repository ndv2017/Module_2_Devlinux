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
        float usage = monitor.get_cpu_stats().get_usage_percent();

        std::cout << "CPU Usage: " << usage << " %" << std::endl;
        // logger_adapter::log(LOG_INFO, "CPU Usage: " + std::to_string(usage) + " %");

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    logger_adapter::log(LOG_INFO, "System monitor stopped.");
    logger_adapter::close();

    return 0;
}
