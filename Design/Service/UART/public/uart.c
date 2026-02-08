#include "uart.h"

typedef struct {
    char name[32];
    UART_Driver_t* driver;
} UART_Driver_Entry_t;

static UART_Driver_Entry_t uart_driver_table[MAX_UART_DRIVERS];
static int driver_cnt = 0;

int uart_register_driver(const char* name, UART_Driver_t* driver) {
    if(driver_cnt >= MAX_UART_DRIVERS) {
        return -1;
    }
    strcpy(uart_driver_table[driver_cnt].name, name, sizeof(uart_driver_table[driver_cnt].name));
    uart_driver_table[driver_cnt].driver = driver;
    driver_cnt++;
    return 0;
}

UART_Driver_t* uart_get_driver(const char* name) {
    for(int i = 0; i < driver_cnt; ++i) {
        if(strcmp(uart_driver_table[i].name, name) == 0) {
            return uart_driver_table[i].driver;
        }
    }
    return NULL;
}


/* Public API */
int uart_init(const char* name, int port) {
    UART_Driver_t* driver = uart_get_driver(name);
    if(driver && driver->init) {
        return driver->init(port);
    }
    return -1;
}

int uart_write(const char* name, int port, const char* data, int length) {
    UART_Driver_t* driver = uart_get_driver(name);
    if(driver && driver->write) {
        return driver->write(port, data, length);
    }
    return -1;
}

int uart_read(const char* name, int port, char *buffer, int length) {
    UART_Driver_t* driver = uart_get_driver(name);
    if(driver && driver->read) {
        return driver->read(port, buffer, length);
    }
    return -1;
}
