# Advanced C/C++ and System Design - Module 2 Devlinux

This module focuses on strengthening core knowledge in advanced C/C++ programming, system design, and software engineering best practices.

## Repository Structure

### [01__Clean_Code](01__Clean_Code/BT1/)
Practices Clean Code principles and C coding conventions through a Library Management System project.
- **[BT1_Library_Management_System](01__Clean_Code/BT1/)**: Implements a Library Management System that adheres to Clean Code principles, focusing on readability, maintainability, and modularity. The project includes features for managing books, users, and borrowing operations while following best practices in C programming.

### [02__Design_Pattern](02__Design_Pattern/)
Applies fundamental software design patterns to embedded C projects.

#### Creational
- **[BT1_Singleton](02__Design_Pattern/Creational/BT1_Singleton/)**: Ensures a single instance of a `sensor_manager` for centralized sensor data handling.
- **[BT2_Factory](02__Design_Pattern/Creational/BT2_Factory/)**: Implements a flexible sensor interface using the Factory Pattern for open/closed system design.
- **[BT3_Builder](02__Design_Pattern/Creational/BT3_Builder/)**: Simplifies UART configuration setup using the Builder Pattern.

#### Structural
- **[BT2_Facade](02__Design_Pattern/Structural/BT2_Facade/)**: Unifies control of subsystems in a smart home via a high-level Facade interface.

#### Behavioral
- **[BT1_Observer](02__Design_Pattern/Behavioral/BT1_Observer/)**: Implements an event notification system using the Observer Pattern for smart home sensors and devices.
- **[BT2_State_Machine](02__Design_Pattern/Behavioral/BT2_State_Machine/)**: Models a music player using the State Pattern to manage transitions between playing, paused, and stopped states.

### [03_Variable_N_Data_Types](03_Variable_N_Data_Types/)
Explores advanced usage of variables, enums, structs, and state management in embedded C.

- **[BT1_SPWS](03_Variable_N_Data_Types/BT1_SPWS/)**: Implements a smart plant watering system that uses sensor data, structured state handling, and simulated hardware control to manage automated and manual watering modes.

### [04_Standard_I_O](04_Standard_I_O/)
Focuses on advanced input/output operations, including file handling and logging.
- **[BT1_Logger](04_Standard_I_O/BT1_Logger/)**: Develops a professional logger module that supports multi-target logging, level filtering, and automatic metadata addition for debugging and monitoring applications.
