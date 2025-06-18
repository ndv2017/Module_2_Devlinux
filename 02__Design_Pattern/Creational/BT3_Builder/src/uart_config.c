#include "uart_config.h"

static uart_builder_t* set_baud_rate(uart_builder_t* builder, uint32_t baud_rate) {
    if (baud_rate < BAUD_RATE_1200 || baud_rate > BAUD_RATE_115200) {
        printf("Error: Invalid baud rate. Must be between 1200 and 115200.\n");
        return builder;
    }

    builder->config.baud_rate = baud_rate;
    return builder;
}

static uart_builder_t* set_parity(uart_builder_t* builder, uint8_t parity) {
    if (parity != PARITY_EVEN && parity != PARITY_ODD && parity != PARITY_NONE) {
        printf("Error: Invalid parity. Must be 0 (None), 1 (Odd), or 2 (Even).\n");
        return builder;
    }

    builder->config.parity = parity;
    return builder;
}

static uart_builder_t* set_stop_bits(uart_builder_t* builder, uint8_t stop_bits) {
    if (stop_bits != STOP_BITS_1 && stop_bits != STOP_BITS_2) {
        printf("Error: Invalid stop bits. Must be 1 or 2.\n");
        return builder;
    }

    builder->config.stop_bits = stop_bits;
    return builder;
}

static uart_builder_t* set_data_bits(uart_builder_t* builder, uint8_t data_bits) {
    if (data_bits != DATA_BITS_8 && data_bits != DATA_BITS_9) {
        printf("Error: Invalid data bits. Must be 8 or 9.\n");
        return builder;
    }

    builder->config.data_bits = data_bits;
    return builder;
}

static uart_config_t build(uart_builder_t* builder) {
    return builder->config;
}

uart_builder_t uart_builder_init(void) {
    uart_builder_t builder = {
        .config = {
            .baud_rate = BAUD_RATE_9600,
            .parity = PARITY_NONE,
            .stop_bits = STOP_BITS_1,
            .data_bits = DATA_BITS_8
        },
        .set_baud_rate = set_baud_rate,
        .set_parity = set_parity,
        .set_stop_bits = set_stop_bits,
        .set_data_bits = set_data_bits,
        .build = build
    };

    return builder;
}
