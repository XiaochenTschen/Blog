#ifndef UART_H
#define UART_H

#include "uart_types.h"

#define MAX_UART_DRIVERS 10

int uart_register_driver(const char* name, UART_Driver_t* driver);
UART_Driver_t* uart_get_driver(const char* name);

/* Public API */
int uart_init(const char* name, int port);
int uart_write(const char* name, int port, const char* data, int length);
int uart_read(const char* name, int port, char *buffer, int length);

#endif /* UART_H */