#ifndef DISK_STATS_H
#define DISK_STATS_H

#include <string>
#include <vector>

#define ROOT_MOUNT_POINT "/"
#define EFI_MOUNT_POINT "/boot/efi"
struct disk_usage_info {
    std::string mount_point;
    uint64_t total_kb;
    uint64_t used_kb;
    float usage_percent;
};

class disk_stats {
public:
    disk_stats();

    void update();

    const std::vector<disk_usage_info>& get_usages() const;

private:
    std::vector<disk_usage_info> usages;

    void update_mount_point(const std::string& path);
};

#endif // DISK_STATS_H
