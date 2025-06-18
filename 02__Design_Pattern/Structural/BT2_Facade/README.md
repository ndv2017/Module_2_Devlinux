**BT2**: Simplifying Smart Home System Control Interface with Facade Pattern

*Description*:
- You are developing software for a central controller (Hub) of a smart home system. This Hub is responsible for managing and coordinating the operations of various subsystems, including:
    1. **Lighting system**: Controls on/off switching and brightness of lights in rooms.
    2. **Security system**: Activates/deactivates alarms, monitors door sensors, motion sensors.
    3. **HVAC system**: Adjusts temperature and operating modes of air conditioners/heaters.

- Each of these subsystems may have its own programming interface (API) with complex initialization, configuration, and control functions. For example, to activate the "Good morning" scenario, the Hub needs to perform a series of operations: gradually increase bedroom light brightness, adjust room temperature to a comfortable level, and possibly disable part of the security system.

- **Problems encountered**: Direct management of subsystems from the Hub's application layer leads to difficulties:
    1. **Complex interface**: The application layer must know and interact with multiple different APIs of each subsystem (lighting, security, HVAC). This makes the application layer's source code messy and difficult to manage.
    2. **Difficult to use and error-prone**: To execute a user scenario (e.g., "Leaving home", "Movie watching"), the application layer must sequentially call multiple functions from different subsystems. This is not only complex but also prone to errors if the order or function call parameters are incorrect.
    3. **Tight coupling**: The application layer source code is heavily dependent on the implementation details of each subsystem. If a subsystem is upgraded or replaced (e.g., switching to a new type of light control module with different API), the application layer source code may need modifications in multiple places.

*Requirements*:
- Propose and implement a solution using Facade Pattern to solve the above problems, ensuring:
    1. **Interface simplification**: Provide a single, higher-level interface (API) that allows the application layer to easily execute common user scenarios (e.g., activateMorningRoutine(), activateAwayMode(), setMovieNightScene()) without needing to concern itself with detailed control of each subsystem.
    2. **Reduce dependency (Loose Coupling)**: The application layer doesn't need to know about the existence or detailed operation methods of lighting, security, or HVAC control modules.
    3. **Increase maintainability and extensibility**: Changes or upgrades to a subsystem have minimal impact on the application layer. Easy addition of new composite scenarios.

*Hint*:
- Use **Facade Pattern** to create a "**SmartHomeFacade**" class that provides simplified methods for complex operations involving multiple subsystems.

---

*Answer*:

- The Facade Pattern is applied to simplify the interface for controlling a smart home system with multiple subsystems (lighting, security, HVAC). Instead of the application layer directly interacting with each subsystem's complex APIs, a single `smart_home_facade_t` structure is introduced, providing high-level functions for common user scenarios.

- In this implementation, the facade exposes functions such as `activate_morning_routine`, `activate_away_mode`, and `activate_movie_night`. Each of these functions internally coordinates the necessary operations across all subsystems (e.g., turning on lights, setting brightness, adjusting HVAC temperature, enabling security modes) in the correct order. The application layer only needs to call these high-level functions, without knowing the details of each subsystem.

- This approach solves the problems as follows:
  - **Interface simplification**: The application layer interacts with a single, unified API for common scenarios, making the code cleaner and easier to manage.
  - **Loose coupling**: The application layer is decoupled from the implementation details of each subsystem. Changes or upgrades to subsystems require minimal or no changes to the application code.
  - **Maintainability and extensibility**: New scenarios can be added easily by extending the facade, without modifying the application layer or existing subsystem code.
