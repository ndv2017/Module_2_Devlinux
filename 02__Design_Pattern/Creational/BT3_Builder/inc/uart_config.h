#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#include <stdio.h>
#include <stdint.h>

#define BAUD_RATE_1200    1200
#define BAUD_RATE_9600    9600
#define BAUD_RATE_115200  115200
#define PARITY_NONE       0
#define PARITY_ODD        1
#define PARITY_EVEN       2
#define STOP_BITS_1       1
#define STOP_BITS_2       2
#define DATA_BITS_8       8
#define DATA_BITS_9       9

typedef struct {
    uint32_t baud_rate;
    uint8_t parity;
    uint8_t stop_bits;
    uint8_t data_bits;
} uart_config_t;

typedef struct uart_builder {
    uart_config_t config;

    struct uart_builder* (*set_baud_rate)(struct uart_builder*, uint32_t);
    struct uart_builder* (*set_parity)(struct uart_builder*, uint8_t);
    struct uart_builder* (*set_stop_bits)(struct uart_builder*, uint8_t);
    struct uart_builder* (*set_data_bits)(struct uart_builder*, uint8_t);
    uart_config_t (*build)(struct uart_builder*);
} uart_builder_t;

uart_builder_t uart_builder_init(void);

#endif // UART_CONFIG_H
