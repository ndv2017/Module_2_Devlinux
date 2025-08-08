#include "disk_stats.h"
#include "logger_adapter.h"
#include <sys/statvfs.h>
#include <vector>

disk_stats::disk_stats() {}

void disk_stats::update() {
    usages.clear();
    update_mount_point(ROOT_MOUNT_POINT);
    update_mount_point(EFI_MOUNT_POINT);
}

void disk_stats::update_mount_point(const std::string& path) {
    struct statvfs stat;
    if (statvfs(path.c_str(), &stat) != 0) {
        logger_adapter::log(LOG_ERROR, "Failed to get disk stats for " + path);
        return;  // Failed to read (ignore)
    }

    float usage;
    uint64_t total = stat.f_blocks * stat.f_frsize / 1024;
    uint64_t free = stat.f_bfree * stat.f_frsize / 1024;
    uint64_t used = total - free;
    // f_blocks: total blocks, f_bfree: free blocks
    // f_frsize: fragment size (block size)
    // stat.f_b... * stat.f_frsize is total bytes, divided by 1024 for KB

    usage = (total == 0) ? 0.0f : (float)used / total * 100.0f;

    disk_usage_info info;
    info.mount_point = path;
    info.total_kb = total;
    info.used_kb = used;
    info.usage_percent = usage;

    usages.push_back(info);
}

const std::vector<disk_usage_info>& disk_stats::get_usages() const {
    return usages;
}
