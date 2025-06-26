# **Logger Module**

Here's the output of the program, which demonstrates the logger functionality:

```shell
[2025-06-26 15:15:59] [INFO] [./main.c:13] - System started.
[2025-06-26 15:15:59] [WARNING] [./main.c:14] - Low battery level: 20%
[2025-06-26 15:15:59] [ERROR] [./main.c:15] - Sensor disconnected!
[2025-06-26 15:15:59] [CRITICAL] [./main.c:16] - Critical failure in module: Motor Controller
[2025-06-26 15:15:59] [DEBUG] [./main.c:19] - Now debugging is visible.
```

   - The logger writes messages to both the console and a file named `log.txt`.
   - When the log level is initialized to `LOG_INFO`, only messages of that level and above are logged. Lower priority messages (like `DEBUG`) are ignored.
   - After changing the log level to `LOG_DEBUG`, all messages are logged, including debug information.

---

## Description of the Assignment:
In real-world applications, using only `printf` for debugging and logging information is **insufficient**. A professional logger system needs the capability to:
1. Write logs to multiple destinations (console, file).
2. Filter log messages based on severity level (e.g., only show errors, ignore debug information).
3. Automatically add useful information like timestamp, filename, and line number to each log message.

This exercise requires you to build a complete logger module that can be configured and used in any C project, adhering to clean code principles and module organization.

## Software Requirements:

### 1. Source Code Structure
   - `logger.h`
   - `logger.c`
   - `main.c`

### 2. Log Levels
Use enum to define 8 log levels according to syslog standard:
   - `LOG_EMERGENCY`
   - `LOG_ALERT`
   - `LOG_CRITICAL`
   - `LOG_ERROR`
   - `LOG_WARNING`
   - `LOG_NOTICE`
   - `LOG_INFO`
   - `LOG_DEBUG`

The following are the levels defined by Syslog in descending order of severity:
1. **Emergency** (`emerg`): indicates that the system is unusable and requires immediate attention.
2. **Alert** (`alert`): indicates that immediate action is necessary to resolve a critical issue.
3. **Critical** (`crit`): signifies critical conditions in the program that demand intervention to prevent system failure.
4. **Error** (`error`): indicates error conditions that impair some operation but are less severe than critical situations.
5. **Warning** (`warn`): signifies potential issues that may lead to errors or unexpected behavior in the future if not addressed.
6. **Notice** (`notice`): applies to normal but significant conditions that may require monitoring.
7. **Informational** (`info`): includes messages that provide a record of the normal operation of the system.
8. **Debug** (`debug`): intended for logging detailed information about the system for debugging purposes.

### 3. Log Format
Each log line must have the following standard format:
   - **[YYYY-MM-DD HH:MM:SS] [LEVEL] [FILENAME:LINE] - Message**
   - Example: `[2024-07-20 11:45:10] [ERROR] [main.c:25] - Failed to connect to database.`

## Functional Requirements:

### 1. Multi-target Logger
   - Logger must be able to write logs simultaneously to console screen (`stderr` for critical errors and `stdout` for normal logs) and a text file.
   - Writing to file is optional and configured during initialization.

### 2. Level Filtering
   - Logger must be configurable with a minimum log level (e.g., `LOG_INFO`).
   - Any message with lower priority (higher numeric value) than the configured level will be ignored and not logged.
   - Need a function to change this filter level at runtime.

### 3. Automatic Metadata Addition
   - Logger must automatically capture and insert timestamp, source filename, and line number at the beginning of each log message.
   - Hint: Use compiler built-in macros `__FILE__` and `__LINE__`.

### 4. Convenience Interface
   - Create a macro `log_message(...)` so users can call it conveniently without having to manually fill in `__FILE__` and `__LINE__`.

## Goals to Achieve:
1. Master the use of functions with variable argument lists (`stdarg.h`).
2. Proficiently use snprintf and vsnprintf for safe string formatting.
3. Understand and apply file I/O techniques (`fopen`, `fprintf`, `fclose`, `fflush`).
4. Use static to encapsulate state within a C module.
5. Create and use useful macros (`__FILE__`, `__LINE__`).
6. Build a complete, highly reusable C module.

> [!NOTE]
> Do not use Design Patterns.
