#ifndef UART_TYPES_H
#define UART_TYPES_H

#include "common_inc.h"

typedef struct {
    int (*init)(int port);
    int (*write)(int port, const char* data, int length);
    int (*read)(int port, char* buffer, int lenght);
} UART_Driver_t;

#endif /* UART_TYPES_H */