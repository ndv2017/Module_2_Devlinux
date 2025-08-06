# **Embedded System Configuration Monitoring System**

## **1. Project Overview**

This project is an "Embedded System Configuration Monitoring System" designed for the Raspberry Pi Zero platform. The system provides a comprehensive monitoring solution that integrates an IL19341 display with the Raspberry Pi Zero. The goal is to develop a solution that tracks and analyzes key operational parameters of the board in real-time

## **2. Features**

The system is built with two main components:

  * Porting the IL19341 display to the Raspberry Pi Zero, which does not support it by default.
  * Building a monitoring application in userspace. The application uses a graphical interface to display information with various views, from a general dashboard to detailed reports and real-time graphshe monitoring application tracks and displays the following information:

  * **CPU:** Overall CPU usage percentage, per-core distribution, current operating frequency, temperature, and the top 5 processes with the highest CPU usage.
  * **Memory:** Used/free RAM, swap usage, top 5 processes using memory, and cache information.
  * **Storage:** Used/free capacity of partitions, read/write speed, and I/O statistics.
  * **Network:** Current upload/download speed, bandwidth usage, number of connections, and IP addresses for each interface.
  * **System:** Uptime, kernel version, running services, and load average over 1, 5, and 15 minutes.

Advanced features include:

  * **Alerts and Notifications:** The ability to set warning thresholds for various parameters lerts when these thresholds are exceeded og important events# **3. Architecture**

The application is designed using the Model-View-Controller (MVC) architectural pattern
  * **Model ([`core/` directory](./src/core/)):** This is the core of the application, responsible for managing system data collection and logic includes modules for CPU, memory, network, and storage statistics.
  * **View:** The user interface displays real-time data on a dashboard and statistical graphs.
  * **Controller:** This acts as the bridge between the Model and the View, handling user eventsrocesses physical button presses for menu navigation, refreshes the display, and updates the data on the interface.

## **4. Getting Started**

**4.1. Prerequisites**
To build and run this project, you will need the following knowledge:

  * Linux Programming Linux Device Driver & Porting t5 and C++ 

**4.2. File Structure**
The project's code is organized as follows:

```
embedded_monitor/
├── src/
│   ├── main.cpp
│   ├── core/                  # The Model component (data collection and logic)
│   ├── alert/                 # Alert management based on thresholds
│   ├── util/                  # Utility functions
│   └── c_legacy/              # Wrapper for existing C code (logger)
├── config/
│   └── thresholds.conf        # Configuration file for alert thresholds
├── log/
│   └── monitor.log            # Log file
├── Makefile / CMakeLists.txt  # Build system
└── README.md
```

**4.3. Building the Project**
Instructions on how to build the project will go here (e.g., using CMake or a Makefile).

**4.4. Installation**
Instructions on how to install the application on the Raspberry Pi Zero will go here.

## **5. Usage**

Details on how to use the application, including navigating the interface and interpreting the displayed data, will be provided here.

## **6. Troubleshooting**

A troubleshooting guide will be available to help with common issues# **7. License**

This document and its contents are the proprietary product of DevLinux Co., Ltd.. Any unauthorized use, disclosure, or reproduction is strictly prohibited without written permission from DevLinux.