# **Embedded System Configuration Monitoring System**

## **1. Project Overview**

This project is an "Embedded System Configuration Monitoring System" designed for the Raspberry Pi Zero platform. The system provides a comprehensive monitoring solution that integrates an IL19341 display with the Raspberry Pi Zero. The goal is to develop a solution that tracks and analyzes key operational parameters of the board in real-time.

---

Here's the output of the program. The output may vary based on the system configuration and the current state of the system being monitored.

```log
Running monitor_app...
[2025-08-07 17:38:09] [INFO] [src/util/logger_adapter.cpp:8] - System monitor started.
[2025-08-07 17:38:09] [INFO] [src/util/logger_adapter.cpp:8] - Thresholds loaded from: config/thresholds.conf
[2025-08-07 17:38:09] [WARNING] [src/util/logger_adapter.cpp:8] - Disk / usage (89.930252%) exceeded threshold (80.000000%)
[2025-08-07 17:38:09] [WARNING] [src/util/logger_adapter.cpp:8] - Net RX [lo] (112022.015625 KB/s) exceeded threshold (2048.000000 KB/s)
[2025-08-07 17:38:09] [WARNING] [src/util/logger_adapter.cpp:8] - Net TX [lo] (112022.015625 KB/s) exceeded threshold (2048.000000 KB/s)
[2025-08-07 17:38:09] [WARNING] [src/util/logger_adapter.cpp:8] - Net RX [ens33] (168898.859375 KB/s) exceeded threshold (2048.000000 KB/s)
[2025-08-07 17:38:09] [WARNING] [src/util/logger_adapter.cpp:8] - Net TX [ens33] (146797.734375 KB/s) exceeded threshold (2048.000000 KB/s)
===========================================================
CPU Usage: 1.15066 %

RAM Usage: 36.0377 %
Swap Usage: 0 %

Disk /  -> Used: 120024212 KB / 133463668 KB (89.930252 %)

Net [lo]        -> RX: 112022.015625 KB/s, TX: 112022.015625 KB/s
Net [ens33]     -> RX: 168898.859375 KB/s, TX: 146797.734375 KB/s

Uptime: 21808.4 seconds
Load Average    -> 1min: 0.09, 5min: 0.11, 15min: 0.1
Kernel Version: 6.8.0-65-generic
Local Time: 2025-08-07 17:38:09

[2025-08-07 17:38:10] [WARNING] [src/util/logger_adapter.cpp:8] - CPU usage (25.314861%) exceeded threshold (25.000000%)
===========================================================
CPU Usage: 25.3149 %

RAM Usage: 37.8828 %
Swap Usage: 0 %

Disk /  -> Used: 120024248 KB / 133463668 KB (89.930275 %)

Net [lo]        -> RX: 5.666992 KB/s, TX: 5.666992 KB/s
Net [ens33]     -> RX: 28.895508 KB/s, TX: 12.671875 KB/s

Uptime: 21809.4 seconds
Load Average    -> 1min: 0.09, 5min: 0.11, 15min: 0.1
Kernel Version: 6.8.0-65-generic
Local Time: 2025-08-07 17:38:10
```

* This output shows the CPU usage, RAM usage, swap usage, disk usage, network speeds for two interfaces (loopback and Ethernet), system uptime, load averages over 1, 5, and 15 minutes, kernel version, and local time.
* The values will change dynamically based on the system's current state and workload.
* The output is printed every second, showing real-time updates of the monitored parameters.

> [!NOTE]
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

```
embedded_monitor/
├── src/
│   ├── main.cpp
│   ├── core/                  # The Model component (data collection and logic)
│   ├── alert/                 # Alert management based on thresholds
│   ├── util/                  # Utility functions
│   └── c_legacy/              # Wrapper for existing C code (logger module)
├── config/
│   └── thresholds.conf        # Configuration file for alert thresholds
├── log/
│   └── monitor.log            # Log file
├── Makefile / CMakeLists.txt  # Build system
└── README.md
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
