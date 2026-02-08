#include "uart_types.h"

static int uart_a_init(int port) {
    printf("UART_A: Initializing on port %d\n", port);
    return 0;
}

static int uart_a_write(int port, const char *data, int length) {
    printf("UART_A: Writing to port %d: %.*s\n", port, length, data);
    return length;
}

static int uart_a_read(int port, char *buffer, int length) {
    printf("UART_A: Reading from port %d\n", port);
    snprintf(buffer, length, "Data from UART_A");
    return length;
}

static UART_Driver_t uart_a_driver = {
    .init = uart_a_init,
    .write = uart_a_write,
    .read = uart_a_read,
};