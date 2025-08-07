#ifndef ALERT_MANAGER_H
#define ALERT_MANAGER_H

#include "system_monitor.h"
#include "thresholds.h"
#include <unordered_map>
#include <string>

class alert_manager {
public:
    alert_manager();

    void load_thresholds(const std::string& config_path);
    void check(const system_monitor& snapshot);

private:
    thresholds limits;

    std::unordered_map<std::string, bool> alert_state;

    bool check_and_alert(const std::string& key, bool condition, const std::string& message);
};

#endif // ALERT_MANAGER_H
