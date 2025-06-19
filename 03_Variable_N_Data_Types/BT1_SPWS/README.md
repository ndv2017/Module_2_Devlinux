**BT1**: Smart Plant Watering System (SPWS)

*Description*:
Design and program an embedded system to manage plant watering. The system must be capable of reading sensor data, making watering decisions based on configuration parameters, and reporting operational status. The exercise focuses on understanding and implementing a real-world automation system with requirements for state management, data handling, and user interaction.

## 1. Hardware and Resource Assumptions:

1.1. **Microcontroller**: 
   - A common microcontroller with basic resources (GPIO, Timer, ADC, sufficient RAM/Flash for small applications).

1.2. **Sensors**:
   - Soil moisture sensor: Measures soil moisture percentage (e.g., 0-100%).
   - Environmental temperature sensor: Measures ambient air temperature.

1.3. **Devices**:
   - Mini water pump: Controlled to turn ON/OFF watering.
   - Status LED: An RGB LED or three single-color LEDs to display operational status (e.g., Green - normal, Yellow - watering, Red - error/warning).
   - Push buttons: Two physical push buttons:
     - Button 1: Toggle automatic mode ON/OFF.
     - Button 2: Activate manual watering (when system is in standby mode).

1.4. **Communication (simulated)**:
   - Function to send status notifications or important data to a user interface (e.g., print to console, or send via UART/wireless module).

## 2. Software Requirements:

### 2.1. Define Operating States:
- **System Mode**:
   - `MODE_AUTO`: System automatically manages watering based on sensors.
   - `MODE_MANUAL`: System waits for manual commands or automatic mode is locked.

- **Pump Watering State**:
   - `PUMP_OFF`: Pump is not operating.
   - `PUMP_ON`: Pump is operating.

- **LED Status**:
   - `LED_NORMAL`: System operating normally, not watering.
   - `LED_WATERING`: System is watering.
   - `LED_LOW_MOISTURE_ALERT`: Soil moisture too low (not watered yet or insufficient watering).
   - `LED_ERROR`: System error (e.g., sensor failure, pump stuck).

### 2.2. Main Data Structures:
- **Sensor Data**: Need a structure to store values read from soil moisture sensor and environmental temperature.

- **System Settings**: Need a structure to store configuration parameters such as:
   - Minimum moisture threshold to start watering.
   - Maximum moisture threshold to stop watering.
   - Maximum watering time per session.
   - Sensor check cycle (e.g., every 5 minutes).
   - Current mode status (Automatic/Manual).

## 3. Functional Requirements:

### 3.1. System Initialization:
- Set up GPIO pins for sensors, pump, LED, push buttons.
- Set initial default values for system settings (moisture thresholds, watering time, etc.).
- Put system into default `MODE_AUTO` initially.

### 3.2. Read and Process Sensor Data:
- Periodically read values from soil moisture sensor and temperature.
- Store these values in sensor data structure.
- May implement data smoothing (averaging) if needed.

### 3.3. Automatic Watering Control Logic:
- If system is in `MODE_AUTO`:
  - Compare current soil moisture with minimum watering threshold.
  - If moisture is too low and wait time between waterings has elapsed, activate pump.
  - While pump is operating, continue monitoring moisture and stop pump when maximum threshold is reached or maximum watering time is exceeded.

- Need a timer to manage sensor check cycles and watering time.

### 3.4. Pump Control:
   - Turn pump ON/OFF based on control logic decisions.
   - Need functions to control pump state (`turn_pump_on()`, `turn_pump_off()`).

### 3.5. LED Status Control:
   - Always update LED color based on system operational status (normal, watering, low moisture, error).

### 3.6. Push Button Handling:
   - **Auto mode toggle button**: When pressed, switch between `MODE_AUTO` and `MODE_MANUAL`. When switching to `MODE_MANUAL`, ensure water pump is OFF.
   - **Manual watering button**: Only effective when system is in `MODE_MANUAL`. When pressed, activate water pump for a fixed duration (e.g., 10 seconds), then automatically turn off.

### 3.7 Status Notifications:
   - Periodically or when important status changes occur, send notifications about system status (e.g., "Soil moisture: 35%", "Watering...", "Mode: Manual").
   - **Memory optimization**: Avoid using too many fixed character strings (`const char*`) if Flash space is limited. Can use numeric codes or enums to represent notifications.

## 4. Main Operation Flow:

1. After initialization, the system will run in an infinite loop.

2. In each loop iteration, the system will:
   - Check and handle push button events.
   - If in automatic mode, check and process watering logic.
   - Update LED status.
   - May send periodic status reports.
   - Have a small delay to save energy and match operational cycle.

## 5. Implementation Requirements:

- Implement the complete SPWS system functionality using C language.
- Organize source code clearly and readably, with separate header and source files for modules (e.g., `main.c`, `sensors.c`, `watering_logic.c`, `actuators.c`, `buttons.c`, `config.h`).
- Use appropriate enums and structs to manage states and data.
- Manage static and extern variables reasonably to control scope and share data between modules.
- Simulate sensor, water pump, LED, and push button operations by printing console messages and corresponding state changes.
- Ensure the system can smoothly transition between modes and handle situations like moisture too low, too high, or user intervention.

---
<br>

# *My Solution*:
## SPWS Overview – Design Breakdown

**1. Objective:**

- To build an embedded-style smart watering controller using C, simulating sensor readings, system state transitions, and actuator control using modular and maintainable code.

**2. Core Modules**

* **Sensor Handling** (`sensors.c/.h`)
    * Read soil moisture and temperature.
    * Simulated with random values or preset test data.
* **Configuration** (`config.h`)
    * System settings like moisture thresholds, watering duration, and sensor cycle.
    * Stores current mode (auto/manual) and pump state.
* **System Logic / State Machine** (`watering_logic.c/.h`)
    * Implements auto mode logic and watering control based on sensor readings.
    * Manages watering session timing and decision making.
* **Actuators** (`actuators.c/.h`)
    * Control water pump and status LEDs.
    * Simulate by printing actions like "Pump ON", "LED set to RED", etc.
* **Button Handling** (`buttons.c/.h`)
    * Manage press events for mode toggle and manual watering.
    * Simulate via function calls or user input.
* **Main Application** (`main.c`)
    * Initializes the system.
    * Runs the infinite loop: checking buttons, updating logic, printing status, and delaying.

**3. Key State Management Elements**

* **Enums:**
    * `system_mode_t`: `MODE_AUTO`, `MODE_MANUAL`
    * `pump_state_t`: `PUMP_OFF`, `PUMP_ON`
    * `led_status_t`: `LED_NORMAL`, `LED_WATERING`, etc.
* **Data Structures:**
    * `sensor_data_t`: moisture + temperature
    * `system_config_t`: mode, thresholds, timers
* **Timers:** Use counters or timestamps to simulate elapsed time.
* **Notifications:** Console printouts triggered on key state changes or status intervals.

**4. Simulated Environment**

* No real hardware; I/O is simulated through `printf()`.
* Timers mimic delays using loop counters or `sleep()`.
