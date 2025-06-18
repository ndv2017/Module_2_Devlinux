**BT1**: Smart Home Event Notification System Using Observer Pattern

*Description*:
- In a modern smart home, the ability to detect and respond immediately to events (such as door opening, motion detection, smoke, or temperature changes) is a crucial factor. The system needs to ensure that all important information is transmitted immediately to related devices and services, from the homeowner's mobile app to security systems and other automatic control devices. Building a flexible and easily extensible notification mechanism is an interesting challenge in software development.

- Imagine you are developing a smart home management system. This system includes:
    1. **Publisher: Event sources (Sensors):**
        - Door status sensor (closed/open)
        - Motion detection sensor
        - Smoke and water leak sensor
        - Temperature sensor

    2. **Observer: Notification recipients (Devices and services):**
        - Homeowner's mobile application
        - Central security system (alarm sirens)
        - Smart lighting system
        - HVAC control system (air conditioning, ventilation)
        - External security monitoring service (optional)
        - Event logging system

- **Example scenario**: When the "door sensor" detects the main door being opened at midnight, or the "smoke sensor" detects smoke in the kitchen, the system needs to automatically perform a series of actions:
    - Send emergency alerts to the homeowner's mobile app.
    - Activate the alarm siren system.
    - Turn on lights in the event area and emergency exits.
    - Adjust the HVAC system (e.g., turn off ventilation to prevent smoke spread).
    - Record event details in the system log.

- If implemented traditionally, each sensor would have to "know" and directly call each device/service that needs notification. This would lead to problems:
    - **Tight Coupling**: Sensors are rigidly bound to notification receiving systems.
    - **Difficult to extend and maintain**: Adding a new notification receiving device (e.g., a new type of smart speaker) or changing how a device responds would require modifying the source code of multiple sensors.
    - **Complex management**: Difficulty in managing different types of events and corresponding responses.

*Requirements*:
- Apply Observer Pattern to design and implement an event notification system for smart homes. The goal is to build a system where Publishers (e.g., sensors) can notify events to multiple Subscribers (e.g., mobile apps, security systems) without needing to know specific details about those Subscribers. Subscribers register (subscribe) with Publishers to receive notifications and can unsubscribe when no longer needed.
- **Detailed implementation of components:**
    * **Publisher (Event Publisher/Subject):**
        - Role: Represents event sources (e.g., DoorSensor, MotionSensor, SmokeSensor).
        - Responsibilities:
            - Maintain a list of registered Subscriber objects (subscribers: Subscriber[]).
            - Provide methods to manage the subscriber list:
                - subscribe(s: Subscriber): Allows a Subscriber to register for notifications.
                - unsubscribe(s: Subscriber): Allows a Subscriber to unregister.
            - Provide notifySubscribers() method: When an event occurs, this method will iterate through all registered Subscribers and call the update(context) method.
            - May contain state (mainState) and business logic (mainBusinessLogic()) that when changed or executed will trigger notifications.

    * **Subscriber (Subscriber Interface/Observer):**
        - Role: Defines the standard interface for all objects wanting to receive notifications from Publisher.
        - Responsibilities:
            - Declare an update method, e.g., update(context: any). This method will be called by Publisher when an event occurs.
            - context can be event data, or the Publisher object itself (allowing Subscriber to get necessary information directly from Publisher).

    * **Concrete Subscribers (Concrete Subscribers/Concrete Observers):**
        - Role: Concrete classes implementing Subscriber Interface. These are components that will react to notifications from Publisher. Examples: MobileAppNotifier, AlarmSystemController, LightingManager, HVACController, EventLoggingService.
        - Responsibilities:
            - Implement update(context) method to perform specific actions when receiving notifications (e.g., display mobile notifications, activate alarm sirens, turn on lights, log events).
            - Each ConcreteSubscriber will handle notifications in its own way, based on the provided context.

    * **Client (Client/Setup Program):**
        - Role: Responsible for initializing Publisher objects and ConcreteSubscriber objects (e.g., a MobileAppNotifier, an AlarmSystemController).
        - Responsibilities:
            - Register ConcreteSubscribers with appropriate Publishers by calling publisher.subscribe(subscriber) method. Example: doorSensor.subscribe(mobileApp) and doorSensor.subscribe(alarmSystem).

*Goals to achieve when applying Observer Pattern*:
- **High decoupling (Loose Coupling)**: Publisher doesn't need to know about specific ConcreteSubscriber classes, only needs to know about Subscriber Interface.
- **Flexibility and easy extensibility**: Easy to add new ConcreteSubscribers to the system or remove existing Subscribers without needing to modify Publisher source code.
- **Dynamic notification**: Subscribers can be added or removed flexibly during runtime.

---

*Answer*:

- The Observer Pattern is applied to build a flexible and extensible event notification system for smart homes. In this design, sensors (such as the door sensor) act as Publishers, while devices and services (such as mobile apps, alarm systems, and event loggers) act as Subscribers. Publishers maintain a list of registered Subscribers and notify them automatically when an event occurs, without needing to know the details of each Subscriber.

- **Implementation highlights:**
  - **Publisher (door_sensor_t):** Maintains a list of subscribers and provides methods to subscribe, unsubscribe, and notify all subscribers when the door state changes.
  - **Subscriber Interface (subscriber_t):** Defines the `update` method that all concrete subscribers must implement.
  - **Concrete Subscribers:** Includes `mobile_app_notifier`, `alarm_system_controller`, and `event_logger`, each implementing the `update` method to handle notifications in their own way.
  - **Client (main.c):** Sets up the system by creating the publisher and subscribers, registering subscribers to the publisher, and simulating events (door opened/closed).

- **How this solves the problems:**
  - **Loose coupling:** The door sensor does not need to know about the specific types or implementations of its subscribers, only that they implement the subscriber interface.
  - **Easy extensibility:** New notification devices or services can be added simply by implementing the subscriber interface and subscribing to the publisher, without modifying the publisher's code.
  - **Dynamic notification:** Subscribers can be added or removed at runtime, allowing for flexible and dynamic event handling.
