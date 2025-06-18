#include <stdio.h>
#include "uart_config.h"

int main(void) {
    uart_builder_t builder = uart_builder_init();

    // Configure UART using the Builder
    uart_config_t uart_config = builder
        .set_baud_rate(&builder, BAUD_RATE_115200)
        ->set_parity(&builder, PARITY_ODD)
        ->set_stop_bits(&builder, STOP_BITS_2)
        ->set_data_bits(&builder, DATA_BITS_9)
        ->build(&builder);

    printf("UART Configuration:\n");
    printf("Baud Rate: %u\n", uart_config.baud_rate);
    printf("Parity: %u\n", uart_config.parity);
    printf("Stop Bits: %u\n", uart_config.stop_bits);
    printf("Data Bits: %u\n", uart_config.data_bits);

    return 0;
}
