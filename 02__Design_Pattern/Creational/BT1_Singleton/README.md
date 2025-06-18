**BT2**: Embedded Sensor Communication System

*Description*:
- You are developing an embedded system to communicate with various sensors. Initially, the system was only designed to communicate and retrieve data from temperature sensors. However, over time, customers have new requirements: the system needs the ability to measure other parameters, such as humidity, pressure, or light.
- Integrating new sensors (e.g., humidity sensor) requires modifying the current system structure to add APIs for retrieving data from these sensors.
- **This leads to**:
    1. Modifying source code in multiple places, increasing the risk of errors.
    2. Increasing system complexity, making maintenance more difficult.
    3. Reducing long-term stability and scalability of the system.
- The current system does not follow the design principle of extension without modification (**Open/Closed Principle - OCP**). Specifically, any extension requirement (adding new sensors) requires modifying existing source code, leading to the risk of breaking system stability.

*Requirements*:
1. Redesign the system according to the Open/Closed Principle (OCP), so that:
2. Integrating additional new sensors (humidity, pressure, light sensors, etc.) only requires extending the system without modifying old source code.
3. Explain how your design helps solve the problems mentioned above.

*Hint*:
- Use **Factory Pattern** to ensure the system has the ability to extend without modifying existing source code.

---

*Answer*:
- The Factory Pattern is a creational design pattern that provides an interface for creating objects in a super class, but allows subclasses to alter the type of objects that will be created. This pattern is particularly useful when the exact type of the object to be created is not known until runtime.

- In this assignment, the system is redesigned using the Factory Pattern to comply with the Open/Closed Principle (OCP). The `create_sensor()` factory function takes a sensor type (e.g., `SENSOR_TEMPERATURE`, `SENSOR_HUMIDITY`, `SENSOR_LIGHT`) and returns a pointer to a `sensor_t` object with the appropriate initialization and data reading functions.

- Each sensor type (temperature, humidity, light, ...) has its own implementation, but the main code does not need to be modified when adding new sensor types. To add a new sensor:
    1. Define a new sensor type and its corresponding functions.
    2. Extend the factory function to handle the new type.

- This approach solves the problems mentioned above:
    - **No need to modify existing code** when adding new sensors, only extend it.
    - **Reduces risk of errors** and **improves maintainability**.
    - **Enhances scalability** and **long-term stability** of the system.
