#include <iostream>
#include <thread>
#include <chrono>
#include "core/system_monitor.h"

int main() {
    system_monitor monitor;

    while (true) {
        float usage = 0.0f;

        monitor.update();
        usage = monitor.get_cpu_stats().get_usage_percent();
        std::cout << "CPU Usage: " << usage << " %" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
