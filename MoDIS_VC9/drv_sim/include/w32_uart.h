#ifndef WIN32_UART_H
#define WIN32_UART_H

typedef struct
{
	module_type ownerid;
	module_type UART_id;
} UARTStruct;

typedef enum {
	io_low=0,
	io_high
} IO_level;

#endif /* WIN32_UART_H */ 