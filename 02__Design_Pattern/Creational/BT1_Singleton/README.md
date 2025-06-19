**BT1**: Sensor Data Management System

*Description*:
- In a sensor data management system, the requirement is that only one unique instance of the **SensorManager** object is allowed to exist in the entire system. The **SensorManager** object has the main responsibilities of:
    1. Managing and collecting data from sensors (**SensorNode**).
    2. Uploading data to the database efficiently and consistently.

- If we cannot ensure that only one unique SensorManager object is created, the system may encounter serious problems such as:
    1. **Data duplication**: Multiple SensorManager objects may collect the same data from sensors, leading to duplicate data storage in the database.
    2. **Resource conflicts**: Different SensorManager objects may simultaneously access and manipulate shared resources, causing conflicts or unexpected errors.
    3. **Difficult to control**: Managing and monitoring the behavior of multiple SensorManager objects becomes complex, reducing system stability and maintainability.

*Requirements*:
1. Propose and implement a solution to ensure that only one unique instance of the SensorManager object is created in the entire system.
2. Explain how your solution helps solve the mentioned problems.

*Hint*:
- Use **Singleton Pattern**

---

*Answer*:

- The **Singleton Pattern** is a design pattern that restricts the instantiation of a class to one single instance and provides a global point of access to that instance. This is particularly useful in scenarios like the Sensor Manager, where we want to ensure that only one instance exists to manage sensor data and avoid issues like data duplication and resource conflicts.
- In this implementation, the `sensor_manager_t` structure represents the singleton instance of the Sensor Manager. The `get_sensor_manager_instance` function is responsible for creating the instance if it does not already exist and returning a pointer to it. This ensures that any part of the system that needs to access the Sensor Manager will always get the same instance, thus maintaining consistency and preventing issues related to multiple instances.
- This approach solves the problems as follows:
  - **Data Duplication**: By ensuring only one instance of the Sensor Manager exists, we prevent multiple instances from collecting and storing the same sensor data, thus avoiding duplication in the database.
  - **Resource Conflicts**: The singleton instance manages access to shared resources, ensuring that only one instance can manipulate them at a time, thus preventing conflicts.
  - **Control and Monitoring**: With a single instance, it becomes easier to control and monitor the behavior of the Sensor Manager, leading to improved system stability and maintainability.
