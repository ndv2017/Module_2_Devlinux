**BT3**: UART Configuration Management System

*Description*:
- During software development, you often have to work with complex objects that have many attributes and components. For example, when configuring UART communication, you need to set parameters such as:
    1. **Baud rate,**
    2. **Parity,**
    3. **Stop bits,**
    4. **Data bits.**
- However, initializing UART in the conventional way encounters several serious problems as follows:
    1. **Complex initialization process**: There are too many parameters to pass in, easily causing confusion or errors during configuration.
    2. **Dependencies between components**: Configuration parameters may depend on each other, making it difficult to change one part without affecting other parts.
    3. **Difficult to create flexible variants**: When needing to create different UART configurations (e.g., one configuration for temperature sensors and another configuration for wireless communication modules), you have to rewrite or modify source code, reducing reusability and extensibility.

*Requirements*:
- Propose and implement a solution to solve the above problems, ensuring:
    1. The UART initialization process becomes simpler and less error-prone.
    2. Changing or extending UART configuration does not affect other parts.
    3. Easily create different configuration variants without modifying existing source code.
    4. Explain how your solution helps overcome the mentioned problems.

*Hint*:
- Use **Builder Pattern** to manage the initialization process of complex objects like UART configuration.

---

*Answer*:

- The Builder Pattern is applied to manage the initialization of complex UART configuration objects. Instead of passing all parameters at once or using multiple constructors, the builder provides a step-by-step interface to set each configuration parameter (baud rate, parity, stop bits, data bits) in a clear and readable way.

- In this implementation, the `uart_builder_t` structure exposes methods such as `set_baud_rate`, `set_parity`, `set_stop_bits`, and `set_data_bits`. Each method returns the builder itself, allowing for method chaining. The final `build` method constructs the `uart_config_t` object with the specified parameters.

- This approach solves the problems as follows:
  - **Simplifies initialization**: Each parameter is set explicitly, reducing confusion and the risk of errors.
  - **Decouples configuration**: Changing one parameter does not affect others, and dependencies can be managed within the builder.
  - **Enables flexible variants**: Different UART configurations can be created easily by chaining different builder methods, without modifying existing code.
