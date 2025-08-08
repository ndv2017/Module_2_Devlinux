# **Embedded System Configuration Monitoring System**

## **1. Project Overview**

This project is an "Embedded System Configuration Monitoring System" designed for the Raspberry Pi Zero platform. The system provides a comprehensive monitoring solution that integrates an IL19341 display with the Raspberry Pi Zero. The goal is to develop a solution that tracks and analyzes key operational parameters of the board in real-time.

---

Here's the output of the program. The output may vary based on the system configuration and the current state of the system being monitored.

```log
Running monitor app...
============================= System Stats =============================
CPU Usage: 1.48257 %

RAM Usage: 36.8514 %
Swap Usage: 0.0371934 %

Disk [/]        -> Used: 115.14GB, Total: 127.28GB, Usage: 90.46 %
Disk [/boot/efi]        -> Used: 6.09MB, Total: 511.96MB, Usage: 1.19 %

Net [lo]        -> RX: 68461.835938 KB/s, TX: 68461.835938 KB/s
Net [ens33]     -> RX: 55413.992188 KB/s, TX: 59020.109375 KB/s

Uptime: 13465.36 seconds
Load Average    -> 1min: 1.07, 5min: 0.46, 15min: 0.22
Kernel Version: 6.8.0-65-generic
Local Time: 2025-08-08 17:51:51

============================= System Stats =============================
CPU Usage: 20.51 %

RAM Usage: 36.71 %
Swap Usage: 0.04 %

Disk [/]        -> Used: 115.14GB, Total: 127.28GB, Usage: 90.46 %
Disk [/boot/efi]        -> Used: 6.09MB, Total: 511.96MB, Usage: 1.19 %

Net [lo]        -> RX: 9.277344 KB/s, TX: 9.277344 KB/s
Net [ens33]     -> RX: 5.722656 KB/s, TX: 5.423828 KB/s

Uptime: 13466.36 seconds
Load Average    -> 1min: 1.07, 5min: 0.46, 15min: 0.22
Kernel Version: 6.8.0-65-generic
Local Time: 2025-08-08 17:51:52
```

* This output shows the CPU usage, RAM usage, swap usage, disk usage for partitions, network statistics for interfaces, system uptime, load averages, kernel version, and local time.
* The values will change dynamically based on the system's current state and workload.
* The output is printed every second, showing real-time updates of the monitored parameters.

> [!IMPORTANT]
> At this point, the program is running on Ubuntu 22.04 Laptop, **not on Raspberry Pi Zero**.

## **2. Features**

### The system is built with two main components:

  * Porting the IL19341 display to the Raspberry Pi Zero, which does not support it by default.
  * Building a monitoring application in userspace. The application uses a graphical interface to display information with various views, from a general dashboard to detailed reports and real-time graphshe monitoring application tracks and displays the following information:

  * **CPU:** Overall CPU usage percentage, per-core distribution, current operating frequency, temperature, and the top 5 processes with the highest CPU usage.
  * **Memory:** Used/free RAM, swap usage, top 5 processes using memory, and cache information.
  * **Storage:** Used/free capacity of partitions, read/write speed, and I/O statistics.
  * **Network:** Current upload/download speed, bandwidth usage, number of connections, and IP addresses for each interface.
  * **System:** Uptime, kernel version, running services, and load average over 1, 5, and 15 minutes.

### Advanced features include:

  * **Alerts and Notifications:** The ability to set warning thresholds for various parameters lerts when these thresholds are exceeded og important events

> [!NOTE]
> In this project, the focus is on the **monitoring application** and the **alerts/notifications features**.

## **3. Architecture**

### The application is designed using the Model-View-Controller (MVC) architectural pattern
  * **Model ([`core/` directory](./src/core/)):** This is the core of the application, responsible for managing system data collection and logic includes modules for CPU, memory, network, and storage statistics.
  * **View:** The user interface displays real-time data on a dashboard and statistical graphs.
  * **Controller:** This acts as the bridge between the Model and the View, handling user eventsrocesses physical button presses for menu navigation, refreshes the display, and updates the data on the interface.

## **4. Getting Started**

### **4.1. Prerequisites**
To build and run this project, you will need the following knowledge:

  * Linux command line basics
  * Understanding of C/C++ programming
  * Familiarity with Makefile or CMake for building projects (the project uses a Makefile)

### **4.2. File Structure**
The project's code is organized as follows:

```bash
.
├── config
│   └── thresholds.conf
├── log
│   └── monitor.log
├── Makefile
├── README.md
└── src
    ├── alert
    │   ├── alert_manager
    │   │   ├── alert_manager.cpp
    │   │   └── alert_manager.h
    │   └── thresholds
    │       ├── thresholds.cpp
    │       └── thresholds.h
    ├── c_legacy
    │   └── logger
    │       ├── logger.c
    │       └── logger.h
    ├── core
    │   ├── cpu_stats
    │   │   ├── cpu_stats.cpp
    │   │   └── cpu_stats.h
    │   ├── disk_stats
    │   │   ├── disk_stats.cpp
    │   │   └── disk_stats.h
    │   ├── mem_stats
    │   │   ├── mem_stats.cpp
    │   │   └── mem_stats.h
    │   ├── net_stats
    │   │   ├── net_stats.cpp
    │   │   └── net_stats.h
    │   ├── sys_info
    │   │   ├── sys_info.cpp
    │   │   └── sys_info.h
    │   └── system_monitor
    │       ├── system_monitor.cpp
    │       └── system_monitor.h
    ├── main.cpp
    └── util
        ├── config_reader
        │   ├── config_reader.cpp
        │   └── config_reader.h
        └── logger_adapter
            ├── logger_adapter.cpp
            └── logger_adapter.h

18 directories, 27 files
```

### **4.3. Building the Project**
Instructions on how to build the project using Makefile:
1. To build the project:
   ```bash
   make
   ```
2. To run the application:
   ```bash
   make run
   ```
3. To clean the build files:
   ```bash
   make clean
   ```
