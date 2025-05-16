#ifndef GPS_UART_H
#define GPS_UART_H

#include "hardware/uart.h"
#include <stddef.h>

class GPSUART {
public:
    GPSUART(uart_inst_t *uart, uint baudrate);
    bool readNMEASentence(char *buffer, size_t len);  // Reads a full sentence

private:
    uart_inst_t *_uart;
    void initUART(uint baudrate);
};

#endif // GPS_UART_H
