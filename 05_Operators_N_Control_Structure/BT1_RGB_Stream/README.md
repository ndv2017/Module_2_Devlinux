# **RGB Stream**

Here's the output of the program, which demonstrates the functionality of the RGB LED strip driver:

```shell
[2025-07-03 18:30:31] [INFO] [./src/led_driver.c:22] - LED strip initialized with 10 pixels

Initial buffer state:
        Pixel 0: 0x00000000
        Pixel 1: 0x00000000
        Pixel 2: 0x00000000
        Pixel 3: 0x00000000
        Pixel 4: 0x00000000
        Pixel 5: 0x00000000
        Pixel 6: 0x00000000
        Pixel 7: 0x00000000
        Pixel 8: 0x00000000
        Pixel 9: 0x00000000

[2025-07-03 18:30:31] [DEBUG] [./src/led_driver.c:45] - Set pixel 0 color to R:255 G:0 B:0
[2025-07-03 18:30:31] [DEBUG] [./src/led_driver.c:45] - Set pixel 4 color to R:255 G:255 B:255
[2025-07-03 18:30:31] [DEBUG] [./src/led_driver.c:45] - Set pixel 9 color to R:0 G:0 B:255

After setting individual pixels:
        Pixel 0: 0x0000FF00
        Pixel 9: 0x000000FF
        Pixel 4: 0x00FFFFFF

[2025-07-03 18:30:31] [INFO] [./src/led_driver.c:58] - Filled LED strip with color R:0 G:255 B:0
        Pixel 0: 0x00FF0000
        Pixel 1: 0x00FF0000
        Pixel 2: 0x00FF0000
        Pixel 3: 0x00FF0000
        Pixel 4: 0x00FF0000
        Pixel 5: 0x00FF0000
        Pixel 6: 0x00FF0000
        Pixel 7: 0x00FF0000
        Pixel 8: 0x00FF0000
        Pixel 9: 0x00FF0000

[2025-07-03 18:30:31] [INFO] [./src/led_driver.c:31] - LED strip shutdown and memory freed
```

   - The buffer is initialized to all `0`s.
   - Then, the first pixel is set to **Red** `(255, 0, 0)`, the last pixel to **Blue** `(0, 0, 255)`, and a middle pixel to **White** `(255, 255, 255)`.
   - Next, the entire strip is filled with **Green** `(0, 255, 0)`, and the buffer is printed again to confirm all pixels are set to this color.
   - Finally, cleanup is performed.

---

## Description of the Assignment:
Addressable RGB LED strips like **WS2812B** (also known as *NeoPixel*) are very popular in *DIY projects* and commercial products. To control them, a microcontroller doesn't send separate analog signals.

Instead, it sends a stream of digital data sequentially. Each LED chip on the strip will "take" its portion of data, then pass the remainder to the next LED.

The data for each LED is a 24-bit packet (3 bytes) defining its color: 8 bits for Green, 8 bits for Red, and 8 bits for Blue (G-R-B order is a common characteristic of this type of LED). Your task is to write a high-level software "driver" that provides utility functions to create and manage a buffer containing all color data for the entire LED strip, ready to be sent out.

## Software Requirements:

### 1. Color Data Structure:
- Each LED pixel is controlled by a 32-bit `uint32_t` value for easy manipulation. However, only 24 bits are used to contain color data.
- 24-bit format within `uint32_t`:

| Bits (31-24) | Bits (23-16) | Bits (15-8) | Bits (7-0) |
|--------------|--------------|-------------|------------|
| Unused (8 bits) | Green (8 bits) | Red (8 bits) | Blue (8 bits) |
| 0x00 | 0-255 | 0-255 | 0-255 |

### 2. Source Code Structure:
- `led_driver.h`: Define public API for controlling LED strip.
- `led_driver.c`: Implement driver logic.
- `main.c`: Main program to simulate and test the driver.

### 3. File `led_driver.h`

| Function | Description |
|----------|-------------|
| `int led_init(size_t num_pixels);` | Initializes a buffer for the LED strip with the given number of pixels. Returns 0 on success, -1 on failure (e.g., memory allocation failed). |
| `void led_shutdown();` | Frees the memory allocated for the LED strip. |
| `void led_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b);` | Sets the color of a specific pixel at the given 'index'. Uses 3 separate 8-bit values for Red, Green, and Blue. |
| `void led_fill(uint8_t r, uint8_t g, uint8_t b);` | Fills the entire strip with a single color. |
| `void led_clear();` | Turns off all pixels (by setting their color to black). |
| `const uint32_t* led_get_buffer();` | Gets a constant (read-only) pointer to the data buffer, ready to be "sent" out. This function is used for testing purposes in this exercise. |
| `size_t led_get_pixel_count();` | Gets the number of pixels on the LED strip. |

## Functional Requirements:

### 1. Memory Management:
- `led_init()`: Must dynamically allocate a `uint32_t` array with size equal to `num_pixels`. The entire array must be initialized to `0` (black color).
- `led_shutdown()`: Must free the memory allocated by `led_init()` to prevent memory leaks.

### 2. Bit Manipulation for Color Creation (This is the core part):
- The `led_set_pixel_color()` function must take 3 values `r`, `g`, `b` (each 8-bit) and use bit manipulation operators to "pack" them into a single `uint32_t` number according to the specified G-R-B format.
- **Hint**: You will need to use the left shift operator (`<<`) to push the Green and Red values to their correct positions, and the OR operator (`|`) to combine them together.

### 3. Utility Functions:
- `led_fill()`: Must calculate the 32-bit color value once, then loop through the entire buffer and assign this value to all pixels.
- `led_clear()`: A special case of `led_fill()` with color (0, 0, 0).

### 4. Safety and Bounds Checking:
- All functions that accept an index (like `led_set_pixel_color`) must check whether the index is within valid range (0 to `num_pixels - 1`). If not, the function must silently ignore to avoid writing outside memory bounds.

## Testing Guidelines (`main.c`)

Your `main.c` file should perform the following scenarios:

1. Initialize an LED strip with 10 pixels using `led_init(10)`.
2. Check if the buffer is initialized to all 0s.
3. Set the color of the first pixel (index 0) to Red (255, 0, 0).
4. Set the color of the last pixel (index 9) to Blue (0, 0, 255).
5. Set the color of a middle pixel (e.g., index 4) to White (255, 255, 255).
6. Use `led_get_buffer()` function to get a pointer to the data buffer.
7. Print the hexadecimal values of pixels at indices 0, 4, and 9 for validation.
   - Value at index 0 should be `0x0000FF00` (Red).
   - Value at index 9 should be `0x000000FF` (Blue).
   - Value at index 4 should be `0x00FFFFFF` (White).
8. Call `led_fill()` function to set all pixels to Green (0, 255, 0).
9. Check the buffer again to ensure all 10 pixels have the value `0x00FF0000`.
10. Call `led_shutdown()` to free memory.
